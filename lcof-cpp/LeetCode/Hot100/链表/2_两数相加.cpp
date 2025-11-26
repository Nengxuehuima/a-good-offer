1、定义一个虚拟头节点（dummy head），方便操作结果链表。
2、定义指针 p1 指向 l1，p2 指向 l2。
3、定义一个 carry 变量保存进位（初始为 0）。
4、当 p1 或 p2 仍未为空，或者 carry 不为 0 时：
  取 x = p1->val（若p1为空则为0）；
  取 y = p2->val（若p2为空则为0）；
  计算：sum = x + y + carry；
  新节点值为：sum % 10；
  更新 carry = sum / 10；
  将新节点接到结果链表；
  向后移动指针。
5、最后返回 dummy->next 即为结果链表头。

  #include <bits/stdc++.h>
  using namespace std;

struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

class Solution{
public:
  ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    ListNode dummy(0);//虚拟头节点，便于操作
    ListNode* cur = &dummy;//当前操作指针
    int carry = 0;//进位
  
    //l1,l2未空或者car非0时，继续相加
    while(l1 != nullptr || l2 != nullptr || carry != 0)
      {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + carry;
  
        carry = sum / 10;//计算新的进位
        cur->next = new ListNode(sum % 10);//创建新节点保存当前位结果，当前相加结果取个位
        cur = cur->next;
  
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
      }
    return dummy.next;
  }
};

int main(){
  int n1,n2;
  cin>>n1;
  ListNode* l1 = nullptr;
  ListNode* tail1 = nullptr;
  for(int i=0;i<n1;i++)
    {
      int x; cin>>x;
      if(!l1) l1 = tail1 = new ListNode(x);
      else{
        tail1->next = new ListNode(x);
        tail1 = tail1->next;
      }
    }

  cin>>n2;
  ListNode* l2 = nullptr;
  ListNode* tail2 = nullptr;
  for(int i=0;i<n2;i++)
    {
      int x; cin>>x;
      if(!l2) l2 = tail2 = new ListNode(x);
      else{
        tail2->next = new ListNode(x);
        tail2 = tail2->next;
      }
    }

  Solution sol;
  ListNode* res = sol.addTwoNumbers(l1,l2);

  while(res){
    cout<<res->val;
    if(res->next) cout<<" ";
    res = res->next;
  }
  cout<<endl;
  return 0;

}
