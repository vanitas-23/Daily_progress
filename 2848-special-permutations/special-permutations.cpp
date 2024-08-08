int m=1e9+7;
class Solution {
public:
    int f(int n,int mask,vector<int>& arr,int last,vector<vector<int>>& dp)
    {
        if(__builtin_popcount(mask)==n)
        return 1;
        if(dp[last][mask]!=-1)
        return dp[last][mask];
        int curr=0;
        for(int i=n-1;i>=0;i--)
        {
            if(mask&(1<<i))
            continue;
            if(i==last)
            continue;
            if(arr[i]%arr[last]==0 || arr[last]%arr[i]==0)
            curr=(curr%m+f(n,mask|(1<<i),arr,i,dp)%m)%m;
        }
        return dp[last][mask]=curr;
    }
    int specialPerm(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int mask=0;
        vector<vector<int>>dp(n,vector<int>((1<<n),-1));
        for(int i=0;i<n;i++)
        ans=(ans%m+f(n,mask|(1<<i),nums,i,dp)%m)%m;
        return ans;
    }
};