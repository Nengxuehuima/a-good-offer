#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);  // 遇到左括号，压栈
            } else {
                if (st.empty() || st.top() != matching[c]) {
                    return false;  // 栈为空或者栈顶元素不匹配
                }
                st.pop();  // 匹配成功，弹出栈顶元素
            }
        }
        
        return st.empty();  // 最后栈为空，说明括号完全匹配
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    
    if (sol.isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}



思路：

使用 栈 来解决这个问题。

栈：栈是一种后进先出（LIFO）的数据结构，可以帮助我们维护括号的匹配顺序。

遍历字符串中的每个字符：

如果是左括号（'(', '{', '['），就将它压入栈中。

如果是右括号（')', '}', ']'），检查栈顶是否是对应的左括号。如果是，弹出栈顶元素；否则，说明括号不匹配，返回 false。

遍历完成后，如果栈中仍有元素，说明还有未闭合的左括号，返回 false。

如果遍历完成且栈为空，则说明括号有效，返回 true。


unordered_map：
使用一个哈希表 matching 来存储右括号和对应的左括号的配对关系，方便快速查找。


时间复杂度：O(n)，其中 n 是字符串 s 的长度。我们遍历一次字符串，栈的操作（入栈、出栈）都是常数时间操作。

空间复杂度：O(n)，最坏情况下，栈的空间消耗是 O(n)，即当所有括号都是左括号时，栈中会有 n 个元素。
