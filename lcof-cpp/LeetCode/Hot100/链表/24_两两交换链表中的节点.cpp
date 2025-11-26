思路分析：
对链表中的节点，每次取相邻的两个节点；
交换它们的 next 指针；
继续处理后续的节点；
最后返回新的头节点。
迭代法:
新建一个哑节点 dummy，指向 head。
用指针 prev 指向待交换的前一个节点。
每次让 first = prev->next, second = first->next。
调整指针：
移动 prev 到下一组的前驱节点（prev = first）。
循环直到链表尾部。

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
  ListNode* swapPairs(ListNode* head){
    ListNode dummy(0);//定义虚拟头节点，方便操作
    dummy.next = head;
    ListNode* pre = &dummy;
  
    while(pre->next && pre->next->next)  //只要后面还有两个节点就继续交换
      {
        ListNode* first = pre->next;
        ListNode* second = first->next;
  
        pre->next = second;
        first->next = second->next;
        second->next = first;
  
        pre = first;
      }
    return dummy.next;
  }
};

