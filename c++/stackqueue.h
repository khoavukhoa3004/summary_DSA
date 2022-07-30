#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#include <iostream>

template <typename T>
class Node{
   T data;
   Node*pNext;
public:
   Node():pNext(NULL){}
   Node(T dat, Node* next = NULL): data(dat), pNext(next){}
   T getData(){return this->data;}
   Node* getNext(){ return this->pNext;}
   void setData(T dat){this->data = dat;}
   void setNext(Node *next){this->pNext = next;}
   friend class stack;
   friend class queue;
};

template <typename T>
class LinkedList{
private:
   Node<T>* pHead;
   Node<T>* pTail;
   int count;
public:
   LinkedList(): pHead(NULL), pTail(NULL), count(0){}
   int size(){return this->count;}
   void add(T data, int index);
   void removeByIndex(int index);
   void removeByData(T data);
   Node<T>* getNodeByIndex(int index);
   Node<T>* getNodeByData(T data);
   void clear();
   ~LinkedList(){clear();}
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
   ~stack();
};

template <typename T>
class queue{
private: 
   LinkedList<T> root;
public:
   queue();
   void push(T data);
   void pop();
   T front();
   int size(){return root.size();}
   bool empty(){return (root.size() == 0) ? true:false;}
   void clear();
   ~queue(){clear();}

};
#endif