#define ll long long
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        int n=nums1.size();
        vector<int>req(n);
        iota(req.begin(),req.end(),0);
        auto cmp=[&](int a,int b)
        {
            return nums1[a]<nums1[b];
        };
        sort(req.begin(),req.end(),cmp);
        vector<ll>ans(n);
        ll sum=0;
        int pre=-1;
        for(auto i:req)
        {
            if(pre!=-1 && nums1[i]==nums1[pre])
            ans[i]=ans[pre];
            else
            ans[i]=sum;
            pq.push(nums2[i]);
            sum+=nums2[i];
            if(pq.size()>k)
            sum-=pq.top(),pq.pop();
            pre=i;
        }
        return ans;
    }
};