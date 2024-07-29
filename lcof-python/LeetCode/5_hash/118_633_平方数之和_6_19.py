class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if not c:
            return True
        # 个数如果可以表示为两个平方数之和，那么这个数乘以2后仍然可以表示为两个平方数之和
        # 如果两个数都能表示为两个平方数之和，那么它们的乘积也能表示为两个平方数之和
        # c=a^2 + b^2 2 = 1^2 + 1^2 
        while c % 2 == 0:
            c >>= 1
        # 费马平方和定理 一个素数 p 可以表示为两个平方数之和，当且仅当 𝑝≡1(mod4) 或 𝑝=2
        # 合数的情况 c 包含形如4k+3 的素数因子，并且这些因子的幂次是奇数，那么 c 不能表示为两个平方数之和 
        # 因为偶数的化 如 7 *7 是可以对自身分解的

        # 素数情况
        # 1 如果4k+3 直接返回False 如果有大于1个就不会 49 = 0^2 +7^2 49%4 = 1
        if c % 4 == 3:
            return False

        # 合数->唯一分解定理 可以分解为唯一的素数相乘
        # 2 4k+3 的素数因子的幂次必须为偶数
        for i in range(3, int(sqrt(c))+1, 4):
            # 记录其素数因子个数
            count = 0
            # 49 //7 // 7 count = 2 可以分解
            while c % i == 0:
                c //= i
                count += 1
            if count % 2 != 0:
                return False
        return True
    
# class Solution:
#     def judgeSquareSum(self, c: int) -> bool:
#         if c == 0:
#             return True
#         from math import isqrt
#         myset = set()
#         for i in range(1,isqrt(c) + 1):
#             myset.add(i**2)
#         for j in range(isqrt(c) + 1):
#             if (c - j**2) in myset:
#                 return True
#         return False