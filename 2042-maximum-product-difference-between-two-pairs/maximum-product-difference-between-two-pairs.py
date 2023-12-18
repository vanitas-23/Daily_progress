class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        return mul(*nlargest(2, nums)) - mul(*nsmallest(2, nums))