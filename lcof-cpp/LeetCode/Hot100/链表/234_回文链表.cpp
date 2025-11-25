解题思路
方法：快慢指针 + 反转链表（高效 O(n)）
核心思路：
1、使用快慢指针找到链表中点。
  快指针一次走两步，慢指针一次走一步；
  当快指针走到末尾时，慢指针到达中点。
2、反转后半部分链表。
  前半部分与后半部分逐个比较。
（可选）将链表恢复为原状（面试常要求）。
返回结果。

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x) , next(nullptr) {}
};

class Solution{
public:
//反转链表
  ListNode* reverseList(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
  
    while(cur != nullptr)
      {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
    return pre;
  }

//判断是否为回文链表
  bool isPalindrome(ListNode* head){
    if(!head || !head->next)  return true;//空链表或者单节点必定回文
  
    //快慢指针找到中点
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next)
      {
        fast = fast->next->next;
        slow = slow->next;
      }
  
    //翻转后半部分
  
    ListNode* secondHalf = reverseList(slow);
  
    //比较前半部分和反转后半部分是否相同
    ListNode* p1 = head;
    ListNode* p2 = secondHalf;
    bool isPalin = true;
  
    while(p2) // 后半部分长度 <= 前半部分
      {
       if(p1->val != p2->val)
       {
         isPalin = false;
         break;
       }
        p1 = p1->next;
        p2 = p2->next;
      }
  
    reverseList(secondHalf);//恢复链表
  
    return isPalin;
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 输入格式: [1,2,2,1]
    string input;
    getline(cin, input);
    vector<int> nums;

    // 解析输入字符串为整数数组
    for (int i = 0; i < (int)input.size(); ++i) {
        if (isdigit(input[i]) || input[i] == '-') {
            int num = 0, sign = 1;
            if (input[i] == '-') sign = -1, i++;
            while (i < input.size() && isdigit(input[i])) {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            nums.push_back(num * sign);
        }
    }

    // 构建链表
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : nums) {
        if (!head) head = tail = new ListNode(val);
        else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }

    // 调用判断函数
    Solution sol;
    bool ans = sol.isPalindrome(head);

    // 输出结果
    cout << (ans ? "true" : "false") << "\n";

    return 0;
}
