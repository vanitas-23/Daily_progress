class Solution {
public:
    long long f(vector<int>& arr,int i,int n,int k,vector<int>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[i+1]!=-1)
        return dp[i+1];
        long long mx=-1;
        long long res=0;
        for(int j=i+1;j<i+k+1 && j<n ;j++)
        {
            mx=max(mx,arr[j]*1LL);
            res=max(res,mx*(j-i)+f(arr,j,n,k,dp));
        }

        return dp[i+1]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return f(arr,-1,n,k,dp);
    }
};