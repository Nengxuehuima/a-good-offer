思路分析
1、虚拟头节点：使用 dummy 指向链表头，方便处理头部翻转。
2、分组处理：
  从当前节点开始，找到第 k 个节点；
  如果不足 k 个，结束；
  否则将这 k 个节点翻转。
3、翻转函数：
  常规“反转链表”操作，只反转指定区间 [head, tail]。
4、连接新旧链表：
  翻转后更新前后指针的连接。

#include <bits/stdc++.h>
using namespace std;

// 单链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
//翻转[head，tail]之间的链表
//返回{新的头节点，新的尾节点}

pair<ListNode* ,ListNode*> reverseGroup(ListNode* head,ListNode* tail)
{
  ListNode* pre = tail->next;
  ListNode* cur = head;

  while(pre != tail)
    {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  return {tail,head};
}

ListNode* reverseKGroup(ListNode* head,int k){
  ListNode dummy(0);
  dummy.next = head;
  ListNode* pre = &dummy;

  while(true){
    ListNode* tail = pre;
    //检查剩余节点是否>= k
    for(int i =0;i<k;i++)
      {
        tail = tail->next;
        if(!tail) return dummy.next;//不足k个。直接返回
      }

    ListNode* next = tail->next;//保存下一段起点
    //翻转[head,tail]
    auto [newHead,newTail] = reverseGroup(pre->next,tail);

    //重新连接前后链表
    pre->next = newHead;
    newTail->next = next;

    //移动pre到下一组前驱节点
    pre = newTail;
  }
  return dummy.next;
}


};
