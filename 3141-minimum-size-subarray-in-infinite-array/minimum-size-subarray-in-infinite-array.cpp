#define ll long long
class Solution {
public:
    int f(vector<int>& nums,int tar)
    {
        if(tar==0)
        return 0;
        int n=nums.size();
        vector<ll>pre(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        pre[i]+=pre[i-1];
        int ans=INT_MAX;
        map<ll,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(pre[i]-tar)!=mp.end())
            ans=min(ans,i-mp[pre[i]-tar]);
            mp[pre[i]]=i;
        }
        return ans;
    }
    int minSizeSubarray(vector<int>& nums, int target) {
        ll x=accumulate(nums.begin(),nums.end(),0ll);
        int n=nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        ll ans=LONG_MAX;
        // cout<<x;
        
        if(x==target)
        ans = n;
        else if(x>target)
        ans= f(nums,target);
        else{
        ans = n*(target/x)+f(nums,target%x);
        // cout<<target%x;
        // cout<<target/x;
        }
        // return f(nums,target);
        return ans>=INT_MAX?-1:ans;
    }
};