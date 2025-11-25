迭代法（双指针）思路：
  使用两个指针 p1、p2，分别遍历链表 l1、l2。
  每次比较 p1->val 和 p2->val，取较小者接入新链表。
  直到其中一个链表为空，再接上剩余的部分。
技巧：
  使用一个“虚拟头节点（dummy）”，简化拼接逻辑。
  最后返回 dummy->next。


#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
  //定义虚拟头节点
  ListNode dummy(0);
  ListNode* tail = &dummy;//尾指针，负责拼接新链表

  //迭代遍历两个链表
  while(l1 && l2)
    {
      if(l1->val <= l2->val){
        tail->next = l1;//接上l1较小的节点
        l1 = l1->next;
      }else{
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
  //拼接剩余部分
  tail->next = l1 ? l1 : l2;
  return dummy->next;
    }
};
