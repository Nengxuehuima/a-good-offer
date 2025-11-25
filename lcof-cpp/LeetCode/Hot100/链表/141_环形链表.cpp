解题思路
方法：快慢指针（Floyd 判圈算法）
核心思想：
使用两个指针：
  slow 一次走一步；
  fast 一次走两步。
若链表无环，fast 或 fast->next 会先到达 nullptr。
若链表有环，fast 终会与 slow 相遇（相交）。
初始化 slow = head，fast = head；
循环：
  若 fast == nullptr 或 fast->next == nullptr → 无环；
否则移动指针：
  slow = slow->next
  fast = fast->next->next
若 slow == fast → 存在环


  #include <bits/stdc++.h>
  using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  Listnode(int x):val(x) , next(nullptr) {}
};

class Solution{
public;
  bool hasCysle(ListNode* head){
    if(!head || !head->next)  return false;
  
    ListNode* fast = head;
    ListNode* slow = head;
  
    while(fast && fast->next)
      {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)  //相遇，存在环
          return true;
      }
    return false;
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    getline(cin, input); // 输入链表，如 [3,2,0,-4]
    int pos;
    cin >> pos;          // 输入 pos，表示环的位置

    vector<int> nums;
    // 解析输入字符串
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
    vector<ListNode*> nodes; // 保存节点指针，用于建立环
    for (int val : nums) {
        ListNode* node = new ListNode(val);
        nodes.push_back(node);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    // 如果 pos >= 0，则创建环
    if (pos >= 0 && pos < (int)nodes.size()) {
        tail->next = nodes[pos];
    }

    // 调用判断函数
    Solution sol;
    bool ans = sol.hasCycle(head);

    // 输出结果
    cout << (ans ? "true" : "false") << "\n";

    return 0;
}
