#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, vector<bool>& used) {
        // 如果temp中已包含所有元素，则一个排列完成
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        // 尝试每一个元素
        for (int i = 0; i < nums.size(); i++) {
            // 如果元素已经被使用过，跳过
            if (used[i]) continue;
            
            // 做选择
            used[i] = true;
            temp.push_back(nums[i]);
            
            // 递归
            backtrack(nums, temp, result, used);
            
            // 撤销选择
            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false); // 标记数组，记录每个元素是否被使用
        backtrack(nums, temp, result, used);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // 示例输入
    vector<vector<int>> result = sol.permute(nums);
    
    // 输出结果
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}

backtrack 函数：

该函数使用回溯法来生成所有的全排列。

每次递归都会选择一个未使用的数字，加入当前的排列 temp 中，递归调用处理剩下的元素，直到 temp 中的元素数量与 nums 数量相等时，表示一个排列已经完成，将其加入结果 result 中。

回溯时，撤销对当前元素的选择，并尝试其他的元素。

permute 函数：

这个函数是主函数，接受一个数组 nums，然后调用 backtrack 来生成所有的排列。

used 数组：该数组用于标记某个元素是否已被使用，避免重复使用相同的元素。





题目要点：

没有重复数字：数组 nums 中的元素都是唯一的，没有重复的数字。

返回所有可能的全排列：返回所有数字的排列组合，排列顺序可以随意。

数组长度和元素范围：

nums.length 的范围是 [1, 6]，即数组的长度最大为 6。

数字的取值范围是 [-10, 10]。

解题思路：

这个问题属于典型的回溯算法（Backtracking）问题。我们可以通过递归生成所有可能的排列，回溯法的基本思想是：

对于每个位置，我们选择一个元素，并将它加入当前排列中。

然后递归处理剩下的元素，直到排列完成。

每次排列完成后，我们回溯到上一步，尝试其他的元素。



时间复杂度：

O(n!)，其中 n 是 nums 的长度。因为全排列的个数是 n!，每次递归的时间复杂度是 O(n)，所以整体的时间复杂度是 O(n!)。

空间复杂度：

O(n)，其中 n 是数组的长度。递归深度最多为 n，每次递归都需要额外的空间存储当前排列，used 数组的空间复杂度也是 O(n)。



回溯算法 (Backtracking)

回溯算法是一种通过逐步尝试所有可能的解，并且在发现当前路径不符合条件时，能够“回退”到上一步的解法。它是一种基于递归的算法，用于解决组合、排列、子集、求解图问题等。

回溯算法的核心思想是通过尝试所有可能的解来找到符合条件的解，适合用来解决需要穷举所有解的问题。当遇到不满足条件的解时，算法会“回溯”并尝试其他路径，直到找到最终解或所有可能的解。

回溯的基本步骤：

选择：选择一个可能的候选解。

约束：检查当前选择是否满足问题的约束条件。

递归：如果当前解满足条件，则递归处理下一个问题。

回溯：当发现当前路径无法继续有效地向解逼近时，撤销当前选择，返回到上一步，尝试其他选择。

回溯算法的解决过程是树形结构，每一个选择都会形成一个新的分支。如果发现某条路径不满足条件，就会“回退”并尝试其他路径。

典型应用：

排列与组合：

比如求解一个数组的所有排列或组合，回溯算法会通过递归生成所有可能的排列，并且根据条件去筛选符合要求的解。

子集问题：

例如，求一个集合的所有子集，回溯法通过递归遍历每个元素是否被加入当前子集，从而生成所有子集。

图遍历问题：

比如深度优先搜索（DFS）可以视为一种回溯算法，DFS在搜索图的每个节点时，会判断是否可以继续向下搜索，如果不行，则回溯。

解数独、八皇后等：

数独问题和八皇后问题是经典的回溯问题，通过递归和回溯的方法，可以找到所有可能的解。
