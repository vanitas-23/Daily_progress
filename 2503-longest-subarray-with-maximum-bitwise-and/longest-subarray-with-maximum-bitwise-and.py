class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums, key=lambda x:x)
        ans=1
        temp=1
        n=len(nums)
        for i in range(1,n):
            if nums[i-1]==nums[i] and nums[i]==mx:
                temp+=1
            else:
                temp=1
            ans=max(ans,temp)
        return ans

        