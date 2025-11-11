// 解题思路:
// 这个题目可以通过两种方法解决：
// 第一种方法：是借助辅助容器来实现，这种方式比较直观且易于理解。
// 第二种方法：包括寻找链表的中点、反转链表的后半部分、以及合并链表这几个步骤。这种方法老秦更加推荐，因为它涉及了更多的链表操作技巧，如通过快慢指针寻找链表的中点，使用头插法来反转链表等。这不仅有助于深化对链表结构的理解，还能提升解决复杂问题的能力。
// (1). 检查特殊情况：如果链表为空、只有一个节点或只有两个节点，不需要重排，直接返回。
// (2). 寻找链表的中点：使用快慢指针法找到链表的中间节点。快指针每次移动两步，慢指针每次移动一步。当快指针无法继续前进时，慢指针所在的位置即为链表的中点。
// (3). 反转链表的后半部分：从中点的下一个节点开始，反转链表的后半部分。
// (4). 合并链表的前半部分和反转后的后半部分：交替地将前半部分和反转后的后半部分的节点连接起来，完成链表的重排。


#include <iostream>
using namespace std;

//定义单链表结构
struct ListNode
{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

class Solution
{
  public:
  void reorderList(ListNode* head)
  {
    if(!head || !head->next || !head->next->next)  return;
    ListNode* mid = findMiddle(head);//查找中间节点
    ListNode* l1 = head;
    ListNode* l2 = mid->next;
    mid->next = nullptr;//断开链表
    l2 = reverseList(12);//反转链表
    mergeLists(l1 , l2);//合并链表
  }
  
  //查找链表中间节点
  ListNode* findMiddle(ListNode* head)
  {
    ListNode* slow = head , *fast = head;//快慢指针
    while(fast->next && fast->next->next)
      {
        slow = slow->next;
        fast = fast->next->next;
      }
    return slow;
  }
  
  //反转链表
  ListNode* resverseList(ListNode* node)
  {
    ListNode* pre = nullptr , *cur = head;
    while(cur != nullptr)
      {
        ListNode* nextTemp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextTemp;
      }
    return pre;
  }
  
  //合并链表
  void mergeList(ListNode* l1 , ListNode* l2)
  {
    while(l1 && l2)
      {
        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;
  
        l1->next = l2;
        if(!temp1)  break;//如果l1结束，避免添加额外的l2节点
        l2->next = temp1;
  
        l1 = temp1;
        l2 = temp2;
      }
  }
};
int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  Solution solution;
  solution.reorderList(head);

  //打印重拍后的链表
  ListNode* iter = head;
  while(iter)
    {
      cout<<iter->val<<" ";
      iter->next;
    }
  cout<<endl;

  //清理分配的内存
  while(head)
    {
      ListNode* temp = head->next;
      delete head;
      head = temp;
    }
  return 0;
}
