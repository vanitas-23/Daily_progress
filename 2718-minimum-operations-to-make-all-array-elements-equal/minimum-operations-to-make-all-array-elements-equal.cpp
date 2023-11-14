#define ll long long 
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<ll> v;//ans array
        vector<ll> ps;//previous sum array
        sort(nums.begin(),nums.end());
        ll sum = 0,s;
        for(auto &i: nums){sum += i;ps.push_back(sum);}
        int x = 0,n=nums.size();
        for(auto &i: queries){
            x = upper_bound(nums.begin(),nums.end(),i)-nums.begin();//binary search
            if(x==0)
                v.push_back((sum-n*1LL*i));
            else if(x==n)
                v.push_back((x*1LL*i - ps[x-1]));
            else
                v.push_back((x*1LL*i - ps[x-1]) + (sum-ps[x-1]-i*1LL*(n-x)));
        }
        return v;
    }
};