#include <iostream>
using namespace std;

struct ListNode
{
int val;
ListNode* next;
ListNode(int x):val(x),next(nullptr) {}
};

//合并链表函数
ListNode* mergeTwoList(ListNode* List1,ListNode* List2)
{
  ListNode* sentry = new ListNode(0);//设置哨兵节点
  ListNode* cur = sentry;

  while(List1 && List2)
    {
      if(List1->val < List2->val)
      {
        cur->next = List1;
        List1 = List1->next;
      }
      else
      {
        cur->next = List2;
        List2 = List2->next;
      }
      cur = cur->next;
    }
  cur->next = List1 ? List1 : List2;
  ListNode* head = sentry->next;
  delete sentry;//释放哨兵节点
  return head;
}


