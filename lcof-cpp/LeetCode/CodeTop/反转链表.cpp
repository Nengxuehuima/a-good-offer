#include <iostream>
using namespace std;

struct ListNode
{
int val;
ListNode* next;
ListNode(int x):val(x),next(nullptr) {}
}；

ListNode* reverseList(List* head)
{
ListNode* pre = nullptr,* cur = head,* next = nullptr;
while(cur!=nullptr)
{
  next = cur->next;  //保存当前节点的下一节点
  cur->next = pre;  //反转当前节点的指向
  pre = cur;  //更新pre为当前节点
  cur = next;  //移动到原链表的下一节点
}
return pre;  //返回新的头节点
}

//创建链表
ListNode* creatList()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  heat->next->next = new ListNode(3);
  return head;
}

//打印链表
void printfList(ListNode* head)
{
  while(head!=nullptr)
    {
      cout<<head->val<<" ";
      head = head->next;
    }
  cout<<endl;
}

int main()
{
  ListNode* head = creatList();
  printfList(head);
  ListNode* result = reverseList(head);
  printfList(result);

  return 0;
}
