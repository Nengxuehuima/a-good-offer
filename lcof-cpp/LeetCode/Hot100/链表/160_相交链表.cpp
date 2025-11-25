双指针法（最优）
  设两个指针 pA、pB，分别从 headA 和 headB 出发。
  两个指针每次都向前一步。
  当一个指针走到链表末尾时，跳到另一个链表的头。
  最终两个指针相遇的节点就是相交节点；如果都到达空指针，则无交点。
这样可以保证：
  两个指针都走过 lenA + lenB 的长度。
  若相交，必定在交点相遇。
  若不相交，最终都为 nullptr。
步骤
若任一链表为空，返回 nullptr。
定义两个指针 pA = headA、pB = headB。
当 pA != pB：
  若 pA 到末尾，则让它指向 headB；否则 pA = pA->next。
  若 pB 到末尾，则让它指向 headA；否则 pB = pB->next。
循环结束时：
  若有相交，pA == pB 为交点；
  若无相交，pA == nullptr。

#include <bits/stdc++.h>
using namespace std;

//单链表节点定义
struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

//解决方案
class Solution{
public:
  ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
    if(!headA || !headB)  return nullptr;
  
    ListNode* pA = headA;
    ListNode* pB = headB;
  
    //当两个指针不相等时继续移动
    while(pA != pB)
      {
        //A 走完跳到B的头
        pA = (pA == nullptr) ? headB : pA->next;
        //B 走完跳到A的头
        pB = (pB == nullptr) ? headA : pB->next;
      }
    return pA;
  }
};

int main(){
  ListNode* common = new ListNode(8);
  common->next = new ListNode(4);
  common->next = new ListNode(5);

  ListNode* headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next =common;

  ListNode* headB = new ListNode(5);
  headA->next = new ListNode(6);
  headA->next->next = new ListNode(1);
  headA->next->next->next =common;

  Solution sol;
  ListNode* res = sol.getIntersectionNode(headA,headB);

  if(res)
    cout<<"Intersected at '"<<res->val<<"'"<<endl;
  else
    cout<<"No intersection"<<endl;

  return 0;
}
