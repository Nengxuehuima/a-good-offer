#include <iostream>
#include <vector>
#include <unorder_map>

using namespace std;
vector<int> towSum(vector<int>& nums,int target)
{
    unorder_map<int,int> map;  //存储值和对应的索引
    for(int i=0 ; i<nums.size() ; i++)
        {
           int complement = target-nums[i];
            //如果差值已在哈希表，返回结果
            if(map.find(complement) != map.end())
            {
                return {map[complement],i};
            }
            //否则，将当前元素添加到哈希表
            map[nums[i]]=i;    //将当前元素 nums[i] 和它在数组中的索引 i 存入哈希表 map
        }
    return {};//如果没有找到答案，返回空数组
}

int main()
{
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> result = twoSum(nums,target);
    for(int idx : result)
        {
            cout << idx <<" ";
        }
    return 0;
}


//
具体思路：

遍历数组中的每一个元素，计算出该元素和目标值 target 的差值 complement = target - nums[i]。

然后检查差值是否已经存在于哈希表中。如果存在，说明找到了目标值对应的两个数，返回它们的索引。

如果差值不存在，将当前元素加入哈希表。
