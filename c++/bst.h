#ifndef BST_H
#define BST_H

template <typename Key, typename T>
class BST{
private:
   Node* root;
   int count;
public:
   bool add(int index);
   bool removeNonRecursion(Key key);
   Node* removeRecursion(Node* head, Key key);
   Node* search(Key key);
   void clear();
   

   class Node{
      Key key;
      T data;
      Node* pLeft;
      Node* pRight;
   public:
      Node(): pLeft(NULL), pRight(NULL){};
      Node(Key k, T d): key(k), data(d), pLeft(NULL), pRight(NULL){}
      T getData(){return this->data;}
      Key getKey(){return this->key;}
      ~Node(){ 
         pLeft = NULL;
         pRight = NULL;
      }
      friend class BST;
   };
};



#endif