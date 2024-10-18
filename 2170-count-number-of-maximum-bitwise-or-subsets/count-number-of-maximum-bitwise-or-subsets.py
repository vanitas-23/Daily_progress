class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        mx = 0
        for num in nums:
            mx |= num

        @lru_cache(None)
        def f(i: int, curr: int) -> int:
            if i == n:
                return 1 if curr == mx else 0
            nt = f(i + 1, curr)
            t = f(i + 1, curr | nums[i])
            return t + nt

        return f(0, 0)
