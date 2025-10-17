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
