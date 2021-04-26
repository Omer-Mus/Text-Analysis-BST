/*********************************************/
/* Programmer: Omer Mustel                   */        
/* Date:  16 Dec, 2020                       */     
/* Purpose: Stack class array implementation */
 /********************************************/

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
   private:
        T* data;   
        int top;
        int max;
        
   public:
      //Constructor : creates an array of maximum size //specified by the parameter size -  default 
      // maximum size is 100; sets top and max 
      Stack( int size = 100 );
      // Destructor: releases memory allocated 
      ~Stack();
      //Copy constructor
      Stack ( const Stack<T> & other);
      //Overload the assignment operator 
      const Stack<T> & operator= (const Stack<T> & other);
      //Returns current length of stack
      int getLength();
      // Returns true if stack is full, false otherwise
      bool isFull();
      //Returns true if stack is empty, false otherwise
      bool isEmpty();
      //If stack is not full, inserts parameter item 
      // If stack is full, prints error message
      void push (T item);
      //If stack is not empty removes top item
      T pop ();
      // Return the top element of the stack
      T getTop ();
};
#endif
