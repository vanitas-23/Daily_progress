class Solution {
public:
    int f(int i,int n,vector<int>& nums1, vector<int>& nums2,bool isf,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][isf]!=-1)
        return dp[i][isf];
        int last=i-1;
        int ans=0;
        int lst=-1;
        if(isf)
        lst=nums1[last];
        else
        lst=nums2[last];
        if(nums1[i]>=lst)
        ans=max(ans,1+f(i+1,n,nums1,nums2,1,dp));
        if(nums2[i]>=lst)
        ans=max(ans,1+f(i+1,n,nums1,nums2,0,dp));

        return dp[i][isf]=ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        for(int i=0;i<n;i++)
        {
            ans=max(ans,1+f(i+1,n,nums1,nums2,1,dp));
            ans=max(ans,1+f(i+1,n,nums1,nums2,0,dp));
        }
        return ans;
    }
};