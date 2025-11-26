解题思路：双指针（快慢指针）核心思想：
使用两个指针 fast 和 slow：
1、先让 fast 指针先走 n 步；
2、然后 slow 和 fast 一起走；
3、当 fast 走到链表末尾（nullptr）时，slow 指向的节点就是要删除节点的前一个节点。

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

class Solution{
public:
  ListNode* removeNthFromEnd(ListNode* head,int n)
  {
    ListNode dummy(0);//创建虚拟头节点，指向head，方便处理删除头节点的情况
    dummy.next = head;
  
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
  
    for(int i=0;i<=n;i++) // 1️⃣ 先让 fast 指针前进 n+1 步，让 slow 与 fast 之间间隔 n 个节点
      {
        fast = fast->next;
      }
    
    while(fast != nullptr)// 2️⃣ fast 和 slow 一起走，直到 fast 到链表末尾
      {
        slow = slow->next;
        fast = fast->next;
      }
  
    ListNode* temp = slow->next;// 3️⃣ 删除 slow->next（倒数第 n 个节点）
    slow->next = slow->next->next;
    delete temp;
  
    return dummy.next; // 4️⃣ 返回新链表头
  }
};

int main(){
  int n;
  cin>>n;//链表长度
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      if(!head)
      {
        head = tail = new ListNode(x);
      }
      else{
        tail ->next = new ListNode(x);
        tail = tail->next;
      }
    }
  
  int k;
  cin>>k;//删除倒数第K个

  Solution sol;
  head = sol.removeNthFromEnd(head,k);

   // 输出删除后的链表
    ListNode* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
  
}
