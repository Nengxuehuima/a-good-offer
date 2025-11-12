解题思路:
使用快慢指针（Floyd's Tortoise and Hare Algorithm）解决链表中的环问题和找到环入口的详细思路分为两个主要阶段：环的检测和找到环入口。
环的检测
初始化：创建两个指针，slow和fast，它们都从链表的头节点head开始。
移动指针：在每一轮迭代中，slow指针移动一步，fast指针移动两步。这个过程一直继续，直到fast指针到达链表的尾部（表示链表无环），或者fast指针追上slow指针（表示链表中存在环）。
检测环：如果fast指针和slow指针相遇（即fast == slow），这意味着链表中存在环。如果fast指针到达链表的末尾（fast == nullptr或fast->next == nullptr），则链表中不存在环。
找到环入口
一旦检测到链表中存在环，就可以使用下面的方法找到环的入口：
重新定位：将fast（或slow）指针重新定位回链表的头节点head，而另一个指针保留在它们首次相遇的位置。
同速移动：然后，以相同的速度（每次一步）移动两个指针，即fast和slow指针同时各自向前移动。
相遇点即环入口：当这两个指针再次相遇时，它们相遇的节点就是环的入口节点。这是因为从头节点到环入口的距离等于从首次相遇点到环入口的距离。

#include <iostream>
using namespace std;

struct ListNode
{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

//环检测和入口查找函数
ListNode* detectCycle(ListNode* head)
{
  if(head! || !head->next)   return nullptr;

  ListNode* slow = head;//慢指针
  ListNode* fast = head;//快指针

  //阶段一：检查环
  while(fast && fast->next)
    {
      slow = slow->next;//慢指针走一步
      fast = fast->next->next;//快指针走两步

      if(slow == fast)  //检测到环
      {
        //阶段二： 找到环入口
        slow = head;//将slow重新指向head
        while(slow!=fast)// 同速移动两个指针
          slow = slow->next;
          fast = fast->next;
      }
      return slow; //返回环入口节点
    }
  return nullptr;//链表无环
}

int main()
{
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next = head->next;//指向节点2，形成环

  ListNode* cycleStart = detectCycle(head);
    if (cycleStart) {
        cout << "Cycle detected. The cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;

}
