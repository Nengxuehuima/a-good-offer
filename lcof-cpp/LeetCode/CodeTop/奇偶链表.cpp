// 解题思路主要分为以下几个步骤，以达到在O(1)的额外空间复杂度和O(n)的时间复杂度下解决问题的目标：
// (1). 初始化指针：
// 奇数指针odd：这个指针开始时指向链表的第一个节点，即头节点。它将用于遍历并重新连接链表中所有奇数索引的节点。
// 偶数指针even：这个指针开始时指向链表的第二个节点。它将用于遍历并重新连接链表中所有偶数索引的节点。
// 偶数头指针evenHead：由于在最后需要将偶数节点链表连接到奇数节点链表的尾部，因此需要一个额外的指针来保存偶数链表的头节点。
// (2). 遍历和重连：
// 使用odd和even指针遍历整个链表，通过调整next指针来重新排列节点。
// 对于odd指针，每次移动都跳过一个节点，即odd->next = odd->next->next，这样可以保证odd指针始终指向奇数位置的节点。
// 类似地，对于even指针，也是每次跳过一个节点，即even->next = even->next->next，保证even指针始终指向偶数位置的节点。
// 在遍历过程中，需要检查odd->next和even->next是否存在，以防止访问空指针。
// (3). 合并链表：
// 遍历完成后，所有奇数索引的节点已经通过odd指针连接在一起，偶数索引的节点通过even指针连接在一起。
// 此时，将奇数链表的尾部（odd->next）指向偶数链表的头部（evenHead），从而合并两个链表。
// (4). 返回结果：
// 链表的重新排序已完成，返回原始链表的头节点，即head，因为链表的奇数部分仍然以它开始。


#include <iostream>
using namespace std;

struct ListNode
{
int val;
ListNode* next;
ListNode*(int x):val(x) , next(nullptr) {}
};

//奇偶重排函数
ListNode* oddEvenList(ListNode* head)
{
  if(!head || !head->next)   return head;

  ListNode* odd = head , *even = head->next , *evenHead=even;

  while(even && even->next)
    {
      odd = odd->next = even->next;
      even = even->next = odd->next;
    }
  odd->next = evenHead;// 在遍历结束后，将奇数部分的最后一个节点连接到偶数部分的头节点
  return head;// 返回重新排列后的链表的头节点
}
