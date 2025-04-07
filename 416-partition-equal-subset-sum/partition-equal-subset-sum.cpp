class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%2)
        return false;
        int n=nums.size();
        s/=2;
        vector<vector<int>>dp(n+1,vector<int>(s+1));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--)
        for(int j=0;j<=s;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j>=nums[i])
            dp[i][j]|=dp[i+1][j-nums[i]];
        }
        return dp[0][s];
    }
};