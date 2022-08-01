#ifndef BST_H
#define BST_H

#include "stackqueue.h"
#include "stackqueue.cpp"

template <typename Key, typename T>
class BST{
public:
   class BSTNode{
      Key key;
      T data;
      BSTNode* pLeft;
      BSTNode* pRight;
      friend class BST<Key, T>;
      friend class AVL<Key, T>;
   public:
      BSTNode(): pLeft(NULL), pRight(NULL){};
      BSTNode(Key k, T d): key(k), data(d), pLeft(NULL), pRight(NULL){}
      T getData(){return this->data;}
      Key getKey(){return this->key;}
      BSTNode* remove(BSTNode *head, Key key)
      {

      }
      ~BSTNode(){ 
         pLeft = NULL;
         pRight = NULL;
      }
   protected:
      static void clearNode(BSTNode *head)
      {
         if(!head)
            return;
         if(head->pLeft)
            clearNode(head->pLeft);
         if(head->pRight)
            clearNode(head->pRight);
         head->pLeft = NULL;
         head->pRight = NULL;
         delete head;
      }
      
      static BSTNode* getNode(BSTNode* root, Key key)
      {
         if(!root)
            return NULL;
         BSTNode* head = root;
         while(head)
         {
            if(head->key > key)
            {
               head = head->pLeft;
            }
            else if(head->key < key)
               head = head->pRight;
            else
               break;
         }
         return head;
      }
   }; 
private:
   BSTNode* root;
   int count;
public:
   BST(): root(NULL), count(0){}
   bool add(Key key, T data);
   bool removeNonRecursion(Key key);
   T getData(Key key);
   void clear();
   ~BST(){
      clear();
      count = 0;
   }



};

template <typename Key, typename T>
class AVL{
private:
   BSTNode* root;
   
};


#endif