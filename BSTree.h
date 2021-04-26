#include <iostream>
#include <fstream>
#include "Stack.cpp"
using namespace std;
/*****************************************************/
// Programmer: Omer Mustel                           
// Date:  16 Dec, 2020                           
// Purpose: BSTree class declaration. This class
//          provides iterator for the user using Stack
//          class 
/*****************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T>
struct node
{
  T info;
  int counter = 0; //count how many attempts an item tried to get inserted to the tree.
  node *left;
  node *right;
};

template <class T>
class BSTree
{
  private:
    node<T> *root;
    //private memeber functions that contains the actual code.
    //print pre-ordered list.
    void printPreorder(node<T> *);
    //print post-ordered list.
    void printPostorder(node<T> *);
    //print in-ordered list.
    void printInorder(node<T> *);
    //traverse the list and call deleteNode to delete a node
    void deleteItem (node<T> *&, T  );
    //delete nodes
    void deleteNode (node<T> *&);
    //return total nodes
    int totalNodes(node<T> *);

  public:
   //declare BSTIterator class
   class BSTIterator;
    //constructor
    BSTree ();
    //destructor
    ~BSTree ();
    //destroy, used destroy the list.
    void destroy (node<T> *&);
    //assigment operator overload
    const BSTree<T> & operator= (const BSTree<T> &);
    //copy constructor
    BSTree (const BSTree<T> &);
    //copy ffor repeating code in copy constructor and assignment operator.
    void copy ( node<T> *&, node<T> *); 
    //check if empty
    bool isEmpty();
    //inserts item and return if item was insereted or already in the tree.
    void insertItem( T item);
    //dummy function for delete item.
    void deleteItem (T item);
    //return true if item is in the tree.
    bool searchItem( T item);
    //dummy function for pre order print
    void printPreorder();
    //dummy function for  post order print
    void printPostorder();
    //dummy function for in order print
    void printInorder();
    //dummy function for total nodes
    int totalNodes();
    //return start point for inorder traversal of the tree
    BSTIterator begin(); 
    
//Iterator class
//should not have a destructor or delete any nodes.
//that job is for BSTree class.
    class BSTIterator
    {
      private:
        //Stack class object that hold nodes.
        Stack <node<T>*> myStack;
        node<T> *current;
      public:
        BSTIterator();
        //constructor
        BSTIterator(node<T> *&);
        //copy constructor
        BSTIterator(const BSTIterator &);
        //assigment operator overload
        const BSTIterator& operator=(const BSTIterator&);
        //go the the next instance
        void next();
        //gives an end condition to a loop
        bool NullIteration();
        //return the value of the node
        T Info();
        //return the counter of the node
        int Counter();
    };
};



#endif
