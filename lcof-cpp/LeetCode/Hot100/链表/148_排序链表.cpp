最优解一般是使用 归并排序（Merge Sort）。因为：
  链表无法像数组一样随机访问，快排、堆排都不太方便；
  而归并排序可以自然地在链表上实现，空间复杂度也较低。
思路步骤
1、递归终止条件
  如果链表为空或只有一个节点，直接返回。
2、找到链表中点
  使用 快慢指针 找到链表中间节点（slow）。
  fast 一次走两步，slow 一次走一步。
  当 fast 到尾部时，slow 就在中点。
3、分割链表
  把链表分成左右两部分：left 和 right。
  mid->next = nullptr 断开链表。
4、递归排序左右两部分
  left = sortList(left)
  right = sortList(right)
5、合并两个有序链表
  用双指针（类似“合并两个有序链表”的经典题）将两个有序链表合并。
  返回合并后的新链表头

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

class Solution{
public:
  //主函数，归并排序链表
  ListNode* sortList(ListNode* head){
    //递归终止条件
    if(!head || !head->next)  return head;
  
    //快慢指针寻找中点
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* pre = nullptr;
    while(fast && fast->next)
      {
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
      }
    pre->next = nullptr;//断开链表，分为左右两部分
  
    //递归排序左右两部分
  
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);
  
    //合并两个有序链表
    return mergeTwoLists(left,right);
}

private:
//合并两个有序链表
  ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
  {
    ListNode dummy(0);
    ListNode* tail = &dummy;
  
    while(l1 && l2)
      {
        if(l1->val < l2->val)
        {
          tail->next = l1;
          l1 = l1->next;
        }
        else{
          tail->next = l2;
          l2 = l2->next;
        }
        tail = tail->next;
      }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }

};

int main(){
  int x;
  vector<int> vals;
  while(cin>>x) vals.push_back(x);

  //构造链表
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  fot(int v : vlas)
  {
    if(!head) head = tail = new ListNode(v);
    else{
      tail->next = new ListNode(v);
      tail = tail->next;
    }
  }

Solution sol;
ListNode* sorted = sol.sortList(head);

while(sorted){
  cout<<sorted->val;
  if(sorted->next)  cout" ";
  sorted = sorted->next;
}
cout<<endl;

return 0;
}

