class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        print(nums)
        temp=[]
        n=len(nums)
        ans=-1
        temp.append(nums[0])
        for i in range(1,n):
            temp.append(temp[-1]+nums[i])
        for i in range(2,n):
            if(temp[i-1]>nums[i]):
                ans=temp[i]  

        return ans

        