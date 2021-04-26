#include "BSTree.cpp"
#include <string>
#include <math.h>
#include<bits/stdc++.h> 
#define underline "\033[4m"//define underline for couts
/******************************************************
Programmer: Omer Mustel                 
Date:   16 Dec, 2020                                
Purpose: This program analize texts using Binary Search 
         Tree data struture
Input:  any text file   
Output: statistical results of the text.
***************************************************************/


//****************** Prototypes **********************
void averageWordLength(string [], int);
void averageSentenceLength(int, int);

int main() 
{
  BSTree<string> notUnique; //repeated words
  BSTree<string> unique;  //BST for unique words
  BSTree<string> longUnique;
  int longUniqueWords = 0;//counter for long unique words
  int sentLength = 0; //counter for sentence length
  string text[5000];//to read the text
  int counter = 0; //incrementer.

  
  ifstream iop; //open written text file
  iop.open("sample.txt");

  while(iop >> text[counter])
  {
    string temp = ""; //temporary storage to clean the words before entering the trees 
    for (int i = 0 ; i < text[counter].length() ; i++)
    {
      if (!ispunct(text[counter][i]))
        temp += text[counter][i];

      if (ispunct(text[counter][i]) && text[counter][i] != ',' && text[counter][i] != '\'') //end of a sentence is only 
        sentLength++;
    }

    //transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    //unify the words by changing the first letter to upper case
    temp.front() = toupper(temp.front());

    if (unique.searchItem(temp))
    //check if a word is unique. If not, delete it
      unique.deleteItem(temp);
      
    else if (!unique.searchItem(temp) && !notUnique.searchItem(temp)) 
    {//check in both trees if a word exist
      unique.insertItem(temp);

      if(temp.length() > 3)
        longUnique.insertItem(temp);
    }
    notUnique.insertItem(temp);
    counter++;
  }
  iop.close();//close file.

  string usedTooOften = "";
  BSTree<string> :: BSTIterator iter;

  iter = notUnique.begin();
  while(iter.NullIteration())
  {
    //if the word is longer than 3 letters and Counter is larger than  5% (0.05 times text size).
    if (iter.Info().length() > 3 && iter.Counter() > counter*0.05) //build a string of words used too often
        usedTooOften += iter.Info() + "\n";
    
    iter.next();
  }

  cout << underline "\nSUMMARY" << "\033[0m";
  cout << "\n\nText Length: " << counter << " words";
  cout << "\n\nTotal unique words: " << unique.totalNodes();
  cout << "\n\nTotal long unique words: " << longUnique.totalNodes();
  cout << "\n\nAmount of repeated words (not unique): " << notUnique.totalNodes();
  averageWordLength(text, counter);
  averageSentenceLength(counter, sentLength);
  cout << "\n\nWords used too often:\n" << usedTooOften;
  cout <<"\nList of unique words (from A to Z):";

  iter = unique.begin();
  char str = ' ';
  while (iter.NullIteration())
  {
    if (str == iter.Info()[0])
    {
      cout << iter.Info() << endl;
      iter.next();
    }
    else
    {
     while (str < iter.Info()[0])
       str++;

        cout << underline << "\n\nIndex - " << str << "\033[0m" << endl; //underline index for readable output
    }
  }

  return 0;
}

#undef underline
/*******************************************************/
//averageWordLength
//calculate the average length of a word
//return the size of of all the text divided by the
//total amount of characters combined.
/*******************************************************/
void averageWordLength(string arr[], int size)
{
  double total = 0;

  for(int i = 0; i < size; i++)
    total += arr[i].length(); 
  
   total  = ceil(total/size);
   cout << "\nAverage words length: " << total << " - GOOD  👍" << endl;
   if(total > 8)
    cerr << "\nWARNING! Average word length is over 8 characters.";
}
/*******************************************************/
//averageWordLength
//calculate the average length of a word
//return the size of of all the text divided
/*******************************************************/
void averageSentenceLength(int textSize, int totalSentences)
{
  if((textSize/totalSentences) > 10)
    cout << "\nWARNING!!\nyour average sentence length is larger than 10";
  else
    cout << "\nAverage sentence length: " << ceil(textSize/totalSentences) << " - GOOD  👍" << endl;
}
