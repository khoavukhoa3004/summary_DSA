#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#include <iostream>

template <typename T>
class LinkedList{
public:
   class Node{
      T data;
      Node* pNext;
      friend class LinkedList<T>;
   public:
      Node():pNext(NULL){}
      Node(T dat, Node* next = NULL): data(dat), pNext(next){}
      T getData(){return this->data;}
      Node* getNext(){ return this->pNext;}
      void setData(T dat){this->data = dat;}
      void setNext(Node *next){this->pNext = next;}
   };
private:
   Node* pHead;
   Node* pTail;
   int count;
public:
   LinkedList(): pHead(NULL), pTail(NULL), count(0){}
   int size(){return this->count;}
   void add(T data, int index);
   void removeByIndex(int index);
   void removeByData(T data);
   T getDataByIndex(int index);
   T getTail(){
      if(!pTail)
         throw std::out_of_range("Segmentation fault!");
      return pTail->data;
   }
   int find(T data);
   void clear();
   ~LinkedList(){clear();}
   LinkedList<T>& operator=(LinkedList<T>& rhs);
};

template <typename T>
class stack{
private:
   LinkedList<T> root;
public:
   stack(){}
   void push(T data);
   T top();
   void pop();
   bool empty();
   int size(){return root.size();}
   void clear();
   ~stack(){
      root.clear();
   }
   stack& operator=(stack<T>& s)
   {
      this->root = s.root;
      return *this;
   }
};

template <typename T>
class queue{
private: 
   LinkedList<T> root;
public:
   queue(){}
   void push(T data);
   void pop();
   T front();
   int size(){return root.size();}
   bool empty(){return (root.size() == 0) ? true:false;}
   void clear();
   ~queue(){clear();}
   queue& operator=(queue<T>& q){
      this->root = q.root;
      return *this;
   }
};
#endif