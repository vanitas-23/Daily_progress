class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int>mp;
        int n=nums.size();
        long long sum=0;
        long long res=-1e18;
        vector<long long> req(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
            req[i]+=req[i-1];
        req.insert(req.begin(),0);
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]+k)!=mp.end())
                res=max(res,req[i]-req[mp[nums[i]+k]]+nums[i]); 
            if(mp.find(nums[i]-k)!=mp.end())
                res=max(res,req[i]-req[mp[nums[i]-k]]+nums[i]);
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=i;
            else if(req[i]<req[mp[nums[i]]])
                mp[nums[i]]=i;
        }
        return res==-1e18?0:res;
    }
};