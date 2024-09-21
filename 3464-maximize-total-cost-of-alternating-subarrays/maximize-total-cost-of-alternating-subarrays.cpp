class Solution {
public:
    long long f(int i,int n,vector<int>& nums,int sign,vector<vector<long long>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][sign]!=-1e9)
        return dp[i][sign];
        if(sign==0)
        {
            long long t=-nums[i]+f(i+1,n,nums,1,dp);
            long long nt=nums[i]+f(i+1,n,nums,0,dp);
            return dp[i][sign]=max(t,nt);
        }
        return dp[i][sign]=nums[i]+f(i+1,n,nums,0,dp);

    }
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1e9));
        return nums[0]+f(1,n,nums,0,dp);
    }
};