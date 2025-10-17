#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];  // 初始化为第一天的股价
        int maxProfit = 0;  // 初始化最大利润为 0
        
        for (int i = 1; i < prices.size(); ++i) {
            // 计算当前价格卖出的利润
            maxProfit = max(maxProfit, prices[i] - minPrice);
            // 更新最低买入价格
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;  // 输出最大利润

    prices = {7,6,4,3,1};
    cout << sol.maxProfit(prices) << endl;  // 输出最大利润
    
    return 0;
}



minPrice：用来记录到目前为止的最低股价。我们从第一天开始，初始值为 prices[0]。

maxProfit：用来记录我们目前能够获得的最大利润，初始为 0。

遍历数组中的每个价格（从第二天开始）：

计算当前股价卖出的利润：prices[i] - minPrice，更新最大利润。

更新最低买入股价：minPrice = min(minPrice, prices[i])，确保我们始终在最便宜的时候买入。

最后返回 maxProfit，即最大利润。




思路：

贪心算法：我们只需要一次遍历数组，并在每一天维护到目前为止的最低股价以及最大利润。

最低股价：在遍历过程中，我们始终记录目前为止遇到的最低股价，这样就能确保我们始终在最便宜的时候买入。

最大利润：对于每一天的股价，计算当前股价减去最低股价（即假设今天卖出）。同时更新最大利润。

通过一次遍历，既能找到最低股价，又能计算出最大利润。


复杂度分析：

时间复杂度：O(n)，其中 n 是数组 prices 的长度。我们只遍历一次数组。

空间复杂度：O(1)，只用了常数空间来存储 minPrice 和 maxProfit。
