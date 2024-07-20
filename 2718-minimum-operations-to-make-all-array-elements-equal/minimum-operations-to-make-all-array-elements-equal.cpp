#define ll long long
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<ll>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<ll>pre(n+1);
        vector<ll>suf(n+1);
        for(int i=0;i<n;i++)
        pre[i+1]=pre[i]+nums[i];
        for(int i=n-1;i>=0;i--)
        suf[i]=suf[i+1]+nums[i];
        for(int i=0;i<=n;i++)
        cout<<pre[i]<<" "<<suf[i]<<endl;
        for(auto i:queries)
        {
            auto it=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            //cout<<it<<" ";
            ll ans = suf[it]-pre[it]+it*1ll*i-i*1ll*(n-it);
            
            res.push_back(ans);
        }
        return res;
    }
};