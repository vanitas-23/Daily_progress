
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
    
def kdsmain():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()
    
    num_test_cases = len(lines)
    results = []

    for i in range(num_test_cases):
        nums = json.loads(lines[i])
        
        result = Solution().longestSubarray(nums)
        results.append(str(result))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    kdsmain()
    exit(0)
        