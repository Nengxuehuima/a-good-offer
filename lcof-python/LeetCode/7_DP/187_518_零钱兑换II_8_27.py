class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        if not coins:
            return -1
        dp = [0] * (amount+1)
        # 需要满足0时 肯定为1种 都不取 
        dp[0] = 1
        for coin in coins:
            # 找到当前coin 可以满足的情况
            # coins = [2,3] amount=3
            # 第一个循环
            # dp[2] = dp[0] 取一个2
            # dp[3] = dp[1] 此时dp[1] = 0 所以没有这种组合
            # 第二个
            # dp[3] = dp[3-3=0]
            for j in range(coin, amount+1):
                dp[j] += dp[j-coin]
        return dp[amount]