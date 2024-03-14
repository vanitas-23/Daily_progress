class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return s(nums, goal) - s(nums, goal - 1);
    }
    int s(vector<int>& nums, int goal) {
        int ans=0;
        int i=0;
        int j=0;
        int sum=0;
        int n=nums.size();
        while(j<n)
        {
            sum+=nums[j];
            while(sum>goal && i<=j)
            {
                
                sum-=nums[i++];
            }
            ans+=(j-i+1);
            j++;
        }
        
        return ans;
    }
};