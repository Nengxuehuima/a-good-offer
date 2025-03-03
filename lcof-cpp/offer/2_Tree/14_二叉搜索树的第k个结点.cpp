/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <memory>
class Solution
{
    int count{0};
    int result{-1};

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */

    void inOrder(TreeNode *proot, int k)
    {
        if (!proot)
            return;
        inOrder(proot->left, k);
        ++count;
        if (count == k)
        {
            result = proot->val;
            return;
        }
        inOrder(proot->right, k);
        return;
    }

    int KthNode(TreeNode *proot, int k)
    {
        if (proot == nullptr)
            return -1;
        count = 0;
        result = -1;
        inOrder(proot, k);
        return result;
    }
};