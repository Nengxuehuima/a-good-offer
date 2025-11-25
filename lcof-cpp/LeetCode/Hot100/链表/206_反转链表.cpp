解题思路
迭代法（双指针）   这个方法是最常用、最易理解且高效的。
核心思想：
  使用三个指针：prev、curr、next
  从头到尾遍历链表，逐个反转每个节点的 next 指向。
步骤：
  1、初始化 prev = nullptr，curr = head
  2、遍历链表：
  暂存下一个节点：next = curr->next
  反转当前节点指针：curr->next = prev
  向后移动指针：prev = curr, curr = next
  3、遍历结束后，prev 即为新的头节点。
时间复杂度： O(n)
空间复杂度： O(1)

#include <bits/stdc++.h>
using namespace std;


struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

class Solution{
public:
  ListNode* reverseList(ListNode* head)
  {
    ListNode* pre = nullptr;//前一节点
    ListNode* cur = head;//后一节点
  
    //遍历链表
    while(cur != nullptr)
      {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
    return pre;
  }
};

int main(){
  ios::sync_with_stido(false);
  cin.tie(nullptr);

  string input;
  getline(cin,input);

  vector<int> nums;
  //解析输入
  for(int i=0;i<(int)input.size(),i++)
    {
    if(isdigit(input[i]) || input[i] == '-'){
      int num = 0,sign = 1;
      if(input[i] == '-') sign = -1,i++;
      while(i < input.size() && isdigit(input[i])) {
        num = num * 10 + (input[i] - '0');
        ++i;
      }
      nums.push_back(num * sign);
    }
    }

  //构建链表
  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  for(int val : nums)
    {
      if(!(head))  head = tail = new ListNode(val);
      else{
        tail->next = new ListNode(val);
        tail = tail->next;
      }

    }
  Solution sol;
  ListNode* newHead = sol.reverseLit(head);

  cout<<"[";
  bool first = true;
  while(newHead){
    if(!first) cout<<",";
    cout<<newHead->val;
    first = false;
    newHead = newHead->next;
  }
  cout<<"]\n";
  return 0;
}
