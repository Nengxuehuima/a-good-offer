#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // 用于存储值和对应的下标
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // 计算差值
        if (map.find(complement) != map.end()) { // 如果差值在哈希表中
            return {map[complement], i}; // 返回差值的下标和当前下标
        }
        map[nums[i]] = i; // 将当前数值和下标存入哈希表
    }
    return {}; // 如果没有找到答案，返回空数组
}
//添加main() 为ACM模式
int main() {
    vector<int> nums = {2, 7, 11, 15}; // 示例输入
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    // 输出结果
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}


// 题目中有几个要点需要注意：

// 每种输入只会对应一个答案，也就是说在数组中有且仅有一对数的和是 target。

// 不能使用同一个元素两次，即同一个下标的元素不能被重复使用。

// 题目允许按任意顺序返回答案。

// 思路：

// 为了在数组中找到两个数的下标，我们可以使用哈希表（unordered_map）来解决这个问题，具体的解题步骤如下：

// 遍历数组的每个元素。

// 对于每个元素，计算目标值 target 与该元素的差值 complement。

// 检查哈希表中是否已经存在该差值，如果存在，则说明找到了符合条件的两个数，返回它们的下标。

// 如果差值不存在，则将当前元素添加到哈希表中，继续遍历。
