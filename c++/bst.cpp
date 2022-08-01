#include "bst.h"

template <typename Key, typename T>
bool BST<Key,T>::add(Key key, T data)
{
   if(!root)
   {
      root = new BSTNode(key, data);
   }
   else{
      BSTNode* temp = root;
      while(temp)
      {
         if(temp->key < key)
         {
            if(temp->pLeft)
               temp = temp->pLeft;
            else
            {
               temp->pLeft = new BSTNode(key, data);
               break;
            }
         }
         else
         {
            if(temp->pRight)
               temp = temp->pRight;
            else
            {
               temp->pRight = new BSTNode(key, data);
               break;
            }  
         }
      }
   }
   this->count += 1;
   return true;
}

template <typename Key, typename T>
bool BST<Key,T>::removeNonRecursion(Key key)
{
   /*
   Lấy min node phải để thay thế.
   */
   if(count == 0)
      return false;
   BSTNode* pre_successor = root;
   BSTNode* successor = NULL;
   while(pre_successor)
   {
      if(pre_successor->key == key)
      {
         successor = pre_successor;
         break;
      }
      else if(pre_successor->key > key)
      {
         if(pre_successor->pLeft)
         {
            if(pre_successor->pLeft->key == key)
            {
               successor = pre_successor->pLeft;
               break;
            }  
            else
               pre_successor = pre_successor->pLeft;
         }
         else
         {
            return false;
         }
      }
      else
      {
         if(pre_successor->pRight)
         {
            if(pre_successor->pRight->key == key)
            {
               successor = pre_successor->pRight;
               break;
            }
            else
            {
               pre_successor = pre_successor->pRight;
            }
         }
         else
         {
            return false;
         }
      }
   }
   if(!successor)
      return false;

   if(!successor->pLeft && !successor->pRight)
   {
      if(root == successor)
      {
         root = NULL;
      }
      else
      {
         if(pre_successor->pLeft == successor)
            pre_successor->pLeft = NULL;
         else if(pre_successor->pRight == successor)
            pre_successor->pRight = NULL;
      }
      delete successor;
   }
   if(!successor->pLeft)
   {
      if(root == successor)
         root = successor->pRight;
      else
      {
         if(pre_successor->pLeft == successor)
            pre_successor->pLeft = successor->pRight;
         else if(pre_successor->pRight == successor)
            pre_successor->pRight = successor->pRight;
      }
      successor->pRight = NULL;
      delete successor;
   }
   else if(!successor->pRight)
   {
      if(root == successor)
         root = successor->pLeft;
      else
      {
         if(pre_successor->pLeft == successor)
            pre_successor->pLeft = successor->pLeft;
         else if(pre_successor->pRight == successor)
            pre_successor->pRight = successor->pLeft;
      }
      successor->pLeft = NULL;
      delete successor;
   }
   else
   {
      BSTNode* pre_min_node = successor->pRight;
      while(pre_min_node)
      {
         if(pre_min_node->pLeft)
         {
            if(pre_min_node->pLeft->pLeft)
               pre_min_node = successor->pLeft;
            else
               break;
         }
         else 
            break;
      }
      if(pre_min_node->pLeft == NULL)
      {
         successor->data = pre_min_node->data;
         successor->pRight = pre_min_node->pRight;
         pre_min_node->pRight = NULL;
         delete pre_min_node;
      }
      else
      {
         successor->data = pre_min_node->pLeft->data;
         BSTNode* removedNode = pre_min_node->pLeft;
         pre_min_node->pLeft = removedNode->pRight;

         removedNode->pRight = NULL;
         delete removedNode;
      }
   }
   count -= 1;
   return true;
}

template <typename Key, typename T>
T BST<Key,T>::getData(Key key)
{
   if(!root)
      throw std::out_of_range("Segmentation fault!");
   BSTNode* temp = BSTNode::getNode(this->root, key);
   if(!temp)
      throw "Khong tim duoc du lieu";
   return temp->data;
}

template <typename Key, typename T>
void BST<Key,T>::clear()
{
   BSTNode::clearNode(this->root);
}




int main()
{
   BST<int, int> bst;
   bst.add(5,19);
   bst.add(8, 12);
   bst.add(-3, 12);
   bst.add(35, 11);
   bst.add(6, 31);
   bst.add(7, 12);
   std::cout<<bst.getData(5)<<std::endl;
   std::cout<<((bst.removeNonRecursion(5))?"true":"false")<<std::endl;
}