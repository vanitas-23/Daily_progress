class Solution {
public:
    int f(int i,int j,int n,int m,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp)
    {
        if(i>=n || j>=m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(nums1[i]==nums2[j])
        return dp[i][j]=1 + f(i+1,j+1,n,m,nums1,nums2,dp);
        return dp[i][j]=max(f(i+1,j,n,m,nums1,nums2,dp),f(i,j+1,n,m,nums1,nums2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,nums1,nums2,dp);
    }
};