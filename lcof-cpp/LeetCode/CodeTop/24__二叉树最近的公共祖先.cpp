#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果当前节点为空或是 p 或 q
        if (!root || root == p || root == q) {
            return root;
        }
        
        // 递归寻找左右子树中的结果
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // 如果左右子树都返回非空，说明 root 是公共祖先
        if (left && right) {
            return root;
        }
        
        // 否则，如果左子树为空，返回右子树的结果，反之亦然
        return left ? left : right;
    }
};

// 辅助函数：创建二叉树
TreeNode* buildTree(const vector<int>& nodes, int index = 0) {
    if (index >= nodes.size() || nodes[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);
    return root;
}

int main() {
    Solution sol;

    // 示例1
    vector<int> nodes = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};  // 二叉树的数组表示
    TreeNode* root = buildTree(nodes);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    TreeNode* ancestor = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << ancestor->val << endl; // 输出 3

    // 示例2
    p = new TreeNode(5);
    q = new TreeNode(4);
    ancestor = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << ancestor->val << endl; // 输出 5

    return 0;
}



思路：

递归：我们使用递归的方法，从根节点开始遍历树。

如果当前节点是空的（nullptr），返回空。

如果当前节点就是 p 或者 q，则返回当前节点，因为 p 或 q 本身也可以是它们的祖先。

对当前节点的左右子树分别进行递归查找。

如果左右子树都返回了非空的节点，说明当前节点就是最近公共祖先，因为左右子树分别找到了 p 和 q。

如果只有一侧子树返回非空，说明 p 和 q 都在同一子树中，递归继续向下查找。

递归返回值：每次递归返回的值要么是 p 或 q，要么是当前节点的子树的结果，或者是 nullptr。




TreeNode 结构体：每个节点包含一个值 val 和指向左右子节点的指针 left 和 right。

lowestCommonAncestor 函数：

递归遍历树的每个节点，直到找到节点 p 或 q，或者是空节点。

如果左右子树都找到了目标节点（即返回非空），则当前节点是最近公共祖先。

否则，返回非空的子树结果。

buildTree 辅助函数：用于根据数组表示构建二叉树。

主函数：创建二叉树，调用 lowestCommonAncestor，并输出结果。



时间复杂度：O(n)，其中 n 是二叉树的节点数。我们只需要遍历一遍树的节点。

空间复杂度：O(h)，其中 h 是二叉树的高度，表示递归调用栈的空间。
