class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mn,mx=1,1
        ans=max(nums)
        for n in nums:
            if n==0:
                mx,mn=1,1
                continue
            tmp=n*mx
            mx=max(tmp,n*mn,n)
            mn=min(tmp,n*mn,n)
            ans=max(ans,mx)
        return ans
        
        