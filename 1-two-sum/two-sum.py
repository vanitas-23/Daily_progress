class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp={}
        for i in range(len(nums)):
            mp[nums[i]]=i
        for i in range(len(nums)):
            if target-nums[i] in mp and mp[target-nums[i]]!=i:
                return [mp[target-nums[i]],i]
        return 
        