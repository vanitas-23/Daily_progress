class Solution {
public:
    int f(int i,int n,vector<int>& nums,int k,int mid,vector<int>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=f(i+1,n,nums,k,mid,dp);
        if(mid>=nums[i])
        ans=max(ans,1+f(i+2,n,nums,k,mid,dp));
        return dp[i]=ans;
    }
    bool check(vector<int>& nums,int k,int mid,int n)
    {
        vector<int>dp(n,-1);
        int mx=f(0,n,nums,k,mid,dp);
        return mx>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=1e9+1;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(nums,k,mid,n))
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};