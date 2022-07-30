#include "stackqueue.h"

/*
   method for class LinkedList.
*/
template <typename T>
void LinkedList<T>::add(T data, int index)
{
   /*
   - Add new Node with data at index. 
   * Note: index must be in range [0; size]
   */
   if(index > count || index < 0)
      return;
   if(count == 0)
   {
      pHead = new Node<T>(data);
      pTail = pHead;
   }
   else if(index == count)
   {
      pTail->pNext = new Node<T>(data);
      pTail = pTail->pNext;
   }
   else
   {
      Node<T> *temp = pHead;
      while(index != 1 || index != 0)
      {
         temp = temp->pNext;
      }
      if(index == 0)
      {
         temp = new Node<T>(data);
         temp->pNext = pHead;
         pHead = temp;
      }
      else
      {
         Node<T> *newNode = new Node<T>(data);
         newNode->pNext = temp->pNext;
         temp->pNext = newNode;
      }
   }
   count += 1;
}

template <typename T>
void LinkedList<T>::removeByData(T data)
{
   /* 
      find and remove the first Node having data = data
   */
   if(count == 0)
      return;
   Node<T>* temp = pHead;
   while(temp)
   {
      if(temp->data == data)
         break;
      else if(temp->pNext && temp->pNext->data)
         break;
      temp = temp->pNext;
   }
   if(temp->data = data)
   {
      Node<T>* removedNode = temp;
      pHead = pHead->pNext;
      if(pTail == removedNode)
         pHead = pTail = NULL;
      delete removedNode;
      count -= 1;
   }
   else
   {
      Node<T>* removedNode = temp->pNext;
      temp->pNext = temp->pNext->pNext;
      if(removedNode == pTail)
         pTail = temp;
      delete removedNode;
      count -= 1;
   }
}

template <typename T>
void LinkedList<T>::removeByIndex(int index)
{
   /*
   - remove Node at index. 
   * Note: index must be in range [0; size -1]
   */
   if(index >= count || index < 0)
      return;
   if(index == 0)
   {
      if(count == 1)
      {
         delete pHead;
         pHead = pTail = NULL;
      }
      else
      {
         Node<T>* temp = pHead;
         pHead = pHead->pNext;
         temp->pNext = NULL;
         delete temp;
      }
   }
   else
   {
      Node<T>* temp;
      while(index != 1)
      {
         temp = temp->pNext;
         index -= 1;
      }
      Node<T> *curr = temp->pNext;
      temp->pNext = temp->pNext->pNext;
      if(curr == pTail)
      {
         pTail = temp;
      }
      delete curr;
   }
   count -= 1;
}

template <typename T>
Node<T>* LinkedList<T>::getNodeByIndex(int index)
{
   /*
   - return Node at index. 
   * Note: index must be in range [0; size -1]
   */
   if(index >= count || index < 0)
      return NULL;
   Node<T> *temp = pHead;
   while(index > 0)
   {
      temp = temp->pNext;
   }
   return temp;
}

template <typename T>
Node<T>* LinkedList<T>::getNodeByData(T data)
{
   /*
   - get the first node which data = data. 
   */
   Node<T> *temp = pHead;
   while(temp)
   {
      if(temp->data == data)
         break;
      temp = temp->pNext;
   }
   return temp;
}

template <typename T>
void LinkedList<T>::clear()
{
   while(pHead)
   {
      if(pHead->pNext)
      {
         Node<T>* temp = pHead;
         pHead = pHead->pNext;
         delete temp;
      }
      else
      {
         delete pHead;
      }
   }
   pHead = NULL;
   pTail = NULL;
   count = 0;
}


/*
   method for class stack
*/
template <typename T>
void stack<T>::push(T data)
{
   this->root.add(data, this->root.size());
}

template <typename T>
T stack<T>::top()
{
   return this->root.pTail->data;
}

template <typename T>
void stack<T>::pop()
{
   this->root.removeByIndex(this->root.size() - 1);
}

template <typename T>
bool stack<T>::empty()
{
   return this->root.size() == 0 ? true:false;
}

template <typename T>
void stack<T>::clear()
{
   this->root.clear();
}

/*
   method for class queue
*/
template <typename T>
void queue<T>::push(T data)
{
   this->root.add(data, this->root.size());
}

template <typename T>
T queue<T>::front()
{
   return this->root.pHead->data;
}

template <typename T>
void queue<T>::pop()
{
   this->root.removeByIndex(0);
}

template <typename T>
void queue<T>::clear()
{
   this->root.clear();
}


