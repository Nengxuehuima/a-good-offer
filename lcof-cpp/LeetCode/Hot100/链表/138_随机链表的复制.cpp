#include <bits/stdc++.h>
using namespace std;

//节点定义
class Node{
public:
int val;
Node* next;
Node* random;
Node(int x){
  val = ;
  next = nullptr;
  random = nullptr;
}
};

class Solution{
public:
//方法：原地复制法(O(1))
  Node* copyRandomList(Node* head){
    if(!head)  return nullptr;
  
    //1、复制每个节点并插入原节点后面
    Node* cur = head;
    while(cur){
      Node* newNode = new Node(cur->val);
      newNode->next = cur->next;
      cur->next = newNode;
      cur = newNode->next;
    }
  
    //2、复制random指针
    cur = head;
    while(cur)
      {
        if(cur->random)
          cur->next->random = cur->random->next;//当前节点的下一节点的随机指针指向当前节点随机指针指向节点的下一节点
          cur = cur->next->next;
      }
  
    //3、拆分链表
    Node* newHead = head->next;
    cur = head;
    Node* copy = newHead;
    while(cur)
      {
        cur->next = cur->next->next;
        if(copy->next)
          copy->next = copy->next->next;
        cur = cur->next;
        copy = copy->next;
      }
    return newHead;
  }
};
