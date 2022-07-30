#ifndef STACKQUEUE_H
#define STACKQUEUE_H

template<typename T>
class stack{
private:
   Node* pHead;
   Node* pTail;
   int count;
public:
   stack();
   void push(T data);
   T top();
   void pop();
   bool empty();
   int size();
   void clear();
   ~stack();
   class Node{
      T data;
      Node*pNext;
   public:
      Node(T dat, Node* next = NULL): data(dat), pNext(next){}
      friend class stack;
      friend class queue;
   }
};

template<typename T>
class queue{
private: 
   Node* pHead;
   Node* pTail;
   int count;
public:
   queue();
   void enqueue(T data);
   void dequeue();
   
};

#endif