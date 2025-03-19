class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<=n-3;i++)
        {
            if(nums[i])
            continue;
            ans++;
            nums[i+1]=1-nums[i+1];
            nums[i+2]=1-nums[i+2];
        }
        if(nums[n-1]&nums[n-2])
        return ans;
        return -1;
    }
};