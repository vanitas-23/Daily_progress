class Solution {
public:
    int f(int i,int n,vector<int>& nums, int k,int last,vector<vector<vector<int>>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][k][last+1]!=-1)
        return dp[i][k][last+1];
        int nt=f(i+1,n,nums,k,last,dp);
        int t=0;
        if(last==-1)
        t=1+f(i+1,n,nums,k,i,dp);
        else
        {
            if(nums[last]!=nums[i] && k>0)
            t=1+f(i+1,n,nums,k-1,i,dp);
            else if(nums[last]==nums[i])
            t=1+f(i+1,n,nums,k,i,dp);
        }
        return dp[i][k][last+1]=max(t,nt);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(n+1,-1)));
        return f(0,n,nums,k,-1,dp);
    }
};