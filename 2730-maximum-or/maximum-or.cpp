class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        pre[i]=(pre[i-1]|nums[i]);
        vector<int>suf(n);
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        suf[i]=suf[i+1]|nums[i];
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long x=nums[i];
            long long p,s;
            if(i==0)
            p=0;
            else
            p=pre[i-1];
            if(i==n-1)
            s=0;
            else
            s=suf[i+1];
            ans=max(ans,p|(x<<k)|s);
        }
        return ans;
    }
};