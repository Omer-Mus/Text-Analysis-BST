#include "BSTree.h"
/****************************************************/
// Programmer: Omer Mustel
// Date: 16 Dec, 2020
// Purpose : BSTree class implementation. This class
//           provides iterator for the user using Stack
//           class
// Input: none
// Output: none
/****************************************************/

/*******************************************************/
//Constrcutor
//set root to NULL
/*******************************************************/
template <class T>
BSTree<T> :: BSTree ()
{
  root = NULL;
}

/*******************************************************/
//destructor
// call destroy to destroy and links.
/*******************************************************/
template <class T>
BSTree<T> :: ~BSTree ()
{
  destroy (root);
}

/*******************************************************/
//destroy
//A multi used function to facilitate the copy constructor
//and the assignment operator overload.
//Recursively iterates through the link to delete each link.
/*******************************************************/ 
template <class T>
void BSTree<T> :: destroy (node<T> * &p )
{
  if(p != NULL )
  {
    destroy (p->left);
    destroy (p->right);
    delete p;
    p = NULL;
  }
}

/*******************************************************/
//copy constructor
//A multi used function to facilitate the destructor and 
//ssignment operator overload.
//call copy consturcor and pass the other referance parameter
/*******************************************************/
template <class T>
BSTree<T> :: BSTree (const BSTree<T> & other)
{
  copy(root, other.root );
}

/*******************************************************/
//copy assign operation
//call destroy and then copy. 
/*******************************************************/
template <class T>
const BSTree<T> &  BSTree<T> :: operator= (const BSTree<T> & other)
{
  if(&other != this )
  {
    if(root != NULL )
      destroy (root);
    if(other.root == NULL )
      root = NULL;
    else        
      copy(root, other.root);
  }
  return *this;
}

/*******************************************************/
//copy
//A multi used function to facilitate the copy constructor
//and the assignment operator overload.
//copy the tree recursively.
/*******************************************************/ 
template <class T>
void BSTree<T> :: copy (node<T> *& nroot, node<T> *croot  )
{
  if ( croot == NULL )
    nroot = NULL;
  else
  {
    nroot = new node<T>;
    nroot->info = croot->info;
    copy(nroot->left, croot->left);
    copy(nroot->right, croot->right);
  }   
}

/*******************************************************/
//isEmpty check if the list is empty
/*******************************************************/ 
template <class T>
bool BSTree<T> :: isEmpty ()
{
  return root == NULL;
} 

/*******************************************************/
//printPreorder dummy function
/*******************************************************/ 
template <class T>
void BSTree<T> :: printPreorder ()
{
  printPreorder(root);
}

/*******************************************************/
//printPreorder function, prints in pre order.
/*******************************************************/
template <class T>
void BSTree<T> :: printPreorder (node<T> *p )
{
  if ( p != NULL )
  {
    cout<<p->info<<" ";
    printPreorder(p->left);
    printPreorder(p->right);
  }
}

/*******************************************************/
//printPostorder dummy function
/*******************************************************/
template <class T>
void BSTree<T> :: printPostorder ()
{
  printPostorder(root);
}

/*******************************************************/
//printPostorder function, prints in post order.
/*******************************************************/
template <class T>
void BSTree<T> :: printPostorder (node<T> *p )
{
  if ( p != NULL )
  {
  printPostorder(p->left);
  printPostorder(p->right);
  cout<<p->info<<" ";
  }
}

/*******************************************************/
//printInorder dummy function
/*******************************************************/
template <class T>
void BSTree<T> :: printInorder ()
{
  printInorder(root);
}

/*******************************************************/
//printInorder function, prints in order.
/*******************************************************/
template <class T>
void BSTree<T> :: printInorder (node<T> *p )
{ 
  if ( p != NULL )
  {
  printInorder(p->left);
  cout << p->info << " ";
  printInorder(p->right);
  }
}

/*******************************************************/
//insertItem function, insert an item to the tree if
//the item is NOT in the tree. If an item is in the 
//list, the node that was created for it will be 
//deleteNode an a referance bool variable will be set to
//false. If item is inserted, the bool will be true.
/*******************************************************/
template <class T>
void BSTree<T> :: insertItem (T item)
{
  node<T> *p;
  node<T> *trail;
  node<T> *temp = new node<T>;;

  temp->info = item;
  temp->left = temp->right = NULL;

  if(root == NULL )
    root = temp;
  else
  {
    p = root;

    while(p != NULL )
    {
      trail = p;

      if(p->info == item )
      {
        p->counter+=1;
        delete temp;
        return;
      }
      else if(p->info > item )
        p = p->left;
      else
        p = p->right;  
    }
  
    if(trail->info > item )
      trail->left = temp;
    else
      trail->right = temp;
  }   
}

/*******************************************************/
//searchItem
//iterate through the list and if the item exist, 
//return true
/*******************************************************/
template <class T>
bool BSTree<T> :: searchItem (T item )
{
   bool found;
   node<T> *p;

   found = false;
   p = root;

   while(p != NULL && !found )
   {
      if(p->info == item )
        found = true;
      else if(p->info > item )
        p = p->left;
      else
        p = p->right;            
   }

   return found;
}
/*******************************************************/
//deleteItem dummy function
/*******************************************************/
template <class T>
void BSTree<T> :: deleteItem (T item )
{
   deleteItem(root, item);
}
/*******************************************************/
//deleteItem function, takes the node and the item, search the item, and sends it to deleteNode.
/*******************************************************/
template <class T>
void BSTree<T> :: deleteItem (node<T> *&p, T item )
{
   if(p == NULL )
      cout<<"ITEM NOT IN THE TREE";
   else if(item < p->info )
      deleteItem(p->left, item);
   else if(item > p->info )
      deleteItem(p->right, item);
   else
      deleteNode (p);         
}
/*******************************************************/
//deleteNode delete the item
/*******************************************************/
template <class T>
void BSTree<T> :: deleteNode (node<T> *& p )
{
    node<T> *q;

    q = p;

    if(p->left == NULL )
    {
       p = p->right;
       delete q;
    } 
    else if(p->right == NULL )
    {
       p = p->left;
       delete q;
    }
    else
    {
       node<T> *q = p->left;
       node<T> *r = NULL;

       while(q->right != NULL )
       {
          r = q;
          q = q->right;
       }

       p->info = q->info;

       if(r != NULL )
           r->right = q->left;
       else
          p->left = q->left;    

       delete q;
    }  
}

/*******************************************************/
//totalNodes dummy function
/*******************************************************/
template<class T>
int BSTree<T> :: totalNodes()
{
  return totalNodes(root);
}

/*******************************************************/
//totalNodes counts the amount of nodes and returns it.
/*******************************************************/
template<class T>
int BSTree<T> :: totalNodes(node<T>* p)
{
  int count = 1;
  if (p->left != NULL) 
  {
    count += totalNodes(p->left);
  }
  if (p->right != NULL) 
  {
    count += totalNodes(p->right);
  }
    return count;
}
/*******************************************************/
//BSTIterator funcion to return the root as a start point //to begin iteration
/*******************************************************/
template <class T>
typename BSTree<T> :: BSTIterator BSTree<T> :: begin()
{
  return BSTIterator(root);
}

//***********************************************
//BSTIterator class implementation
//***********************************************
template <class T>
BSTree<T> :: BSTIterator :: BSTIterator()
{
  current = NULL;
}
//***********************************************
//constructor
//***********************************************
template <class T>
BSTree<T> :: BSTIterator :: BSTIterator(node<T> *&p)
{
  current = p;
  while(current->left != NULL)
  {
    myStack.push(current);
    current = current->left;
  }
}

//***********************************************
//copy constructor
//***********************************************
template <class T>
BSTree<T> :: BSTIterator :: BSTIterator(const BSTIterator &other)
{
  current = other.current;
  myStack = other.myStack; //using Stack class = operator overlead for assignment
}

//***********************************************
//copy assign operation
//***********************************************
template <class T>
const typename BSTree<T> :: BSTIterator& BSTree<T> :: BSTIterator :: operator=(const BSTIterator &other)
{
  current = other.current;
  myStack = other.myStack; //using Stack class = operator overlead for assignment
  return *this;
}

//***********************************************
//return end condition for the loop
//***********************************************
template <class T>
bool BSTree<T> :: BSTIterator :: NullIteration()
{
  return !myStack.isEmpty() || (current->right != NULL && current->left != NULL);
}
//***********************************************
//Travers the list in inorder.
//***********************************************
template <class T>
void BSTree<T> :: BSTIterator :: next()
{
  if (current->right != NULL)
  {
    current = current->right;
    while (current->left != NULL)
    {
      myStack.push(current);
      current = current->left;
    }
  }
  else
  {
    current = myStack.getTop();
    myStack.pop();
  }
}
//***********************************************
//return info
//***********************************************
template <class T>
T BSTree<T> :: BSTIterator :: Info()
{
  return current->info;
}
//***********************************************
//return counter
//***********************************************
template <class T>
int BSTree<T> :: BSTIterator :: Counter()
{
  return current->counter;
}

