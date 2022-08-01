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
      this->pHead = new Node(data);
      pTail = pHead;
   }
   else if(index == count)
   {
      pTail->pNext = new Node(data);
      pTail = pTail->pNext;
   }
   else
   {
      Node *temp = pHead;
      while(index != 1 || index != 0)
      {
         temp = temp->pNext;
      }
      if(index == 0)
      {
         temp = new Node(data);
         temp->pNext = pHead;
         pHead = temp;
      }
      else
      {
         Node *newNode = new Node(data);
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
   Node* temp = pHead;
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
      Node* removedNode = temp;
      pHead = pHead->pNext;
      if(this->pTail == removedNode)
         pHead = pTail = NULL;
      delete removedNode;
      count -= 1;
   }
   else
   {
      Node* removedNode = temp->pNext;
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
   if(count == 0)
      throw std::out_of_range("Segmentation fault!");
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
         Node* temp = pHead;
         pHead = pHead->pNext;
         temp->pNext = NULL;
         delete temp;
      }
   }
   else
   {
      Node* temp = pHead;
      while(index != 1)
      {
         temp = temp->pNext;
         index -= 1;
      }
      Node *curr = temp->pNext;
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
T LinkedList<T>::getDataByIndex(int index)
{
   /*
   - return Node at index. 
   * Note: index must be in range [0; size -1]
   */
   if(index >= count || index < 0)
      throw std::out_of_range("Segmentation fault!");
   Node *temp = pHead;
   while(index > 0)
   {
      temp = temp->pNext;
   }
   if(!temp)
      throw std::out_of_range("Segmentation fault!");
   return temp->data;
}

template <typename T>
int LinkedList<T>::find(T data)
{
   /*
   - return idx if found Node;
   otherwise return -1
   */
   int idx = -1;
   Node* temp = pHead;
   while(temp)
   {
      if(temp->data == data)
      {
         idx += 1;
         break;
      }
      else
      {
         idx += 1;
         temp = temp->pNext;
      }
   }
   return idx;
}

template <typename T>
void LinkedList<T>::clear()
{
   while(pHead)
   {
      if(pHead->pNext)
      {
         Node* temp = pHead;
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

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& rhs)
{
   this->clear();
   Node* temp = rhs.pHead;
   while(temp)
   {
      if(this->pHead == NULL)
      {
         this->pHead = new Node(temp->data);
         this->pTail = pHead;
      }
      else
      {
         this->pTail->pNext = new Node(temp->data);
      }
      temp = temp->pNext;
   }
   this->count = rhs.count;
   return *this;
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
   return this->root.getTail();
}

template <typename T>
void stack<T>::pop()
{
   if(this->root.size() == 0)
      throw std::out_of_range("Segmentation fault!");
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
   return this->root.getDataByIndex(0);
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

/*
int main()
{
   queue<int> s;
   s.push(5);
   s.push(10);
   s.push(7);
   s.push(2);
   s.push(15);
   queue<int> q = s;
   while(!q.empty())
   {
      std::cout<<q.front()<<" ";
      q.pop();
   }
   return 0;
}
*/