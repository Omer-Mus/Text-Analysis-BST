// Programmer: Omer Mustel
// Date: 16 Dec, 2020
// Purpose : Stack class implementation file
// Input: none
// Output: none

#include <iostream>
#include "Stack.h"
using namespace std;

/****************************************************/
//Constructor, set the private initialize.
/****************************************************/
template <class T>
Stack<T> :: Stack( int size)
{
   max = size;
   top = -1;
   data = new T[max];
}
/****************************************************/
//Destructor
/****************************************************/
template <class T>
Stack<T> :: ~Stack()
{
  delete [] data;
}

/****************************************************/
//Copy constructor
/****************************************************/
template <class T>
Stack<T> :: Stack ( const Stack<T> & other)
{
   max = other.max;
   top = other.top;
   data = new T[max];
   for ( int i = 0; i <= top; i++ )
     data[i] = other.data[i]; 
}
/****************************************************/
//assigment operator overload.
/****************************************************/
template <class T>
const Stack<T> & Stack<T> :: operator= (const Stack<T> & other)
{
   if ( this != &other )
   {
      delete [] data;
      max = other.max;
      top = other.top;
      data = new T[max];
      for ( int i = 0; i <= top; i++ )
         data[i] = other.data[i]; 
   }
   return *this;
}
/****************************************************/
//getLength, return the amount of elements.
/****************************************************/
template <class T>
int Stack<T> :: getLength()
{
   return top+1;
}
/****************************************************/
//isFull, Check if the stack reached its defined capacity
/****************************************************/
template <class T>
bool Stack<T> :: isFull()
{
   return top+1 == max;
}
/****************************************************/
//isEmpty, check if the stack is empty when top is -1.
/****************************************************/
template <class T>
bool Stack<T> :: isEmpty()
{
   return top == -1;
}
/****************************************************/
//push, insert an item to the top of the stack.
/****************************************************/
template <class T>
void Stack<T> :: push(T item)
{
   if (isFull())
      cout<<"STACK IS FULL";
   else
      data[++top] = item;   
}
/****************************************************/
//pop, delete the top element of the stack.
/****************************************************/
template <class T>
T Stack<T> :: pop()
{
   if ( isEmpty())
    cout<<"";
   else
    top--; 
  return data[-1]; 
}
/****************************************************/
//getTop, return the top element.
/****************************************************/
template <class T>
T Stack<T> :: getTop()
{
     return data[top];   
}
