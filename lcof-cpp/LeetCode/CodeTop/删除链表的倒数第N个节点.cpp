解题思路主要分为以下几个步骤，以达到在O(n)的时间复杂度下解决问题的目标：
(1). 双指针法
这种方法使用两个指针first和second来找到倒数第 n 个节点。具体步骤如下：
步骤 1：初始化两个指针
将first和second都指向链表的头节点。
步骤 2：移动first指针
将first指针向前移动 n 步。这样，first和second之间就保持了 n 步的距离。
步骤 3：同时移动两个指针
同时移动first和second指针，直到first指针达到链表末尾。此时，second指针将指向倒数第 n+1 个节点。
步骤 4：删除倒数第 n 个节点
修改second指针的下一个指针，让它指向倒数第 n 个节点的下一个节点。这样就移除了倒数第 n 个节点。
(2). 特殊情况处理
如果需要删除的是头节点（即倒数第 n 个节点恰好是链表的第一个节点），则在上述过程中，second指针在移动过程中将保持在头节点的位置，因此需要在最后返回head->next，而不是head。
(3). 使用哑节点简化特殊情况
为了避免对头节点的特殊处理，可以在链表的开头添加一个哑节点（dummy node），其next指针指向链表的头节点。这样，即使需要删除头节点，操作也会变得统一。在所有操作完成后，返回哑节点的下一个节点即可，这样可以避免单独处理头节点的情况。

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x):val(x) , next(nullptr) {}
};

//函数：删除链表的倒数第n个节点，并返回链表的头节点
ListNode* removeNthFromEnd(ListNode* head,int n)
{
  ListNode* dummy = new ListNode(0);//创建哑节点，方便对链表的操作
  dummy->next = head;
  ListNode* first = dummy;
  ListNode* seconde = dummy;

  //将first指针向前移动n+1步
  for(int i=0;i<n+1;i++)
    {
      first = first->next;
    }

  //同时移动first和second，知道first为null
  while(first!=null)
    {
      first = first->next;
      second = second->next;
    }

  //删除倒数的n个节点
  ListNode* toBeDelete = second->next;
  second->next = second->next->next;
  delete toBeDelete;

  ListNode* newHead = dummy->next;
  delete dummy;//删除哑节点
  return newHead;
}

void printfList(ListNode* head)
{
  while(head!=nullptr)
  {
    cout<<head->val<<" ";
    head=head->next;
  }
  cout<<endl;
}

int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  head = removeNthFromEnd(head,n);
  printfList(head);

  //清理内存
  while(head!=null)
    {
      ListNode* temp = head;
      head = head->next;
      delete temp;
    }
  return 0;
}

