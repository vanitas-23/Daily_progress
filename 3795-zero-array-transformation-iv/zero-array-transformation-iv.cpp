class Solution {
public:
    int f(int i,int n,vector<int>& x,int tar,vector<vector<int>>& dp)
    {
        if(tar==0)
        return 1;
        if(i==n)
        return 0;
        if(dp[i][tar]!=-1)
        return dp[i][tar];
        int nt=f(i+1,n,x,tar,dp);
        int t=0;
        if(x[i]<=tar)
        t=f(i+1,n,x,tar-x[i],dp);
        return dp[i][tar]=t|nt;
    }
    bool f(int mid,vector<int>& nums, vector<vector<int>>& q)
    {
        int n=nums.size();
        int m=q.size();
        vector<vector<int>>arr(n);
        for(int i=0;i<mid;i++)
        {
            int l=q[i][0];
            int r=q[i][1];
            int val=q[i][2];
            for(int j=l;j<=r;j++)
            arr[j].push_back(val);
        }
        for(int i=0;i<n;i++)
        {
            auto x=arr[i];
            vector<vector<int>>dp(x.size(),vector<int>(nums[i]+1,-1));
            if(f(0,x.size(),x,nums[i],dp))
            continue;
            return 0;
        }
        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l=0;
        int r=q.size();
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(f(mid,nums,q))
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