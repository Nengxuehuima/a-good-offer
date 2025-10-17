#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // nums1 的有效部分的最后一个索引
        int j = n - 1;  // nums2 的最后一个索引
        int k = m + n - 1;  // nums1 的最后一个位置

        // 双指针从后往前填充 nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // 如果 nums2 还有剩余元素
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    
    sol.merge(nums1, m, nums2, n);

    // 输出合并后的结果
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



思路：

双指针法：从 nums1 和 nums2 的末尾开始比较，逐步将较大的元素放到 nums1 的末尾。这样做避免了将元素移动到前面时被覆盖的风险。

维护三个指针：

i 指向 nums1 的有效部分（m-1）。

j 指向 nums2 的末尾（n-1）。

k 指向 nums1 的最后一个位置（m + n - 1）。

每次比较 nums1[i] 和 nums2[j]，把较大的元素放到 nums1[k]，然后调整相应的指针。

如果 nums2 还有剩余的元素，继续放入 nums1。


复杂度分析：

时间复杂度：O(m + n)，每个元素最多被处理一次。

空间复杂度：O(1)，我们直接在 nums1 上进行修改，没有使用额外的空间。
