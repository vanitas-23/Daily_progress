class Solution {
public:
    int f(int i,int n,vector<int>& nums,int curr,int mx, vector<vector<int>>& dp)
    {
        if(i==n)
        return curr==mx;
        if(dp[i][curr]!=-1)
        return dp[i][curr];
        int nt=f(i+1,n,nums,curr,mx,dp);
        int t=f(i+1,n,nums,curr|nums[i],mx,dp);
        return dp[i][curr]=t+nt;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            mx|=nums[i];
        vector<vector<int>>dp(n,vector<int>(mx+1,-1));
        return f(0,n,nums,0,mx,dp);
    }
};