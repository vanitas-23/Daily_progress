class Solution {
public:
    int f(int i,int n,vector<int>& arr,int did,vector<vector<int>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][did]!=-1e9)
        return dp[i][did];
        if(did==0)
        return dp[i][did]=max({arr[i]+f(i+1,n,arr,did,dp),f(i+1,n,arr,1,dp),0});
        return dp[i][did]=max({arr[i]+f(i+1,n,arr,1,dp),0});
    }
    int maximumSum(vector<int>& arr) {
        int ans=-1;
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1e9));
        for(int i=0;i<n;i++)
        ans=max(ans,f(i,n,arr,0,dp));

        return ans==0?*max_element(arr.begin(),arr.end()):ans;
    }
};