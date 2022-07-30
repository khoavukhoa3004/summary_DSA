#ifndef BST_H
#define BST_H

#include "stackqueue.h"
#include "stackqueue.cpp"

template<typename Key, typename T>
class BSTNode{
   Key key;
   T data;
   BSTNode* pLeft;
   BSTNode* pRight;
public:
   BSTNode(): pLeft(NULL), pRight(NULL){};
   BSTNode(Key k, T d): key(k), data(d), pLeft(NULL), pRight(NULL){}
   T getData(){return this->data;}
   Key getKey(){return this->key;}
   ~BSTNode(){ 
      pLeft = NULL;
      pRight = NULL;
   }
   friend class BST;
};

template <typename Key, typename T>
class BST{
private:
   BSTNode<Key,T>* root;
   int count;
public:
   BST(): root(NULL), count(0){}
   bool add(int index);
   bool removeNonRecursion(Key key);
   BSTNode<Key, T>* removeRecursion(BSTNode<Key, T>* head, Key key);
   BSTNode<Key, T>* search(Key key);
   void clear();
   


};



#endif