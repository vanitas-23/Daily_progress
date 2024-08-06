class Solution {
public:
    long long f(int i,int n,vector<int>& nums,long long curr,bool b)
    {
        if(i==n)
        return b?curr:-1e9;
        if(b)
        return max(f(i+1,n,nums,curr,b),f(i+1,n,nums,curr*nums[i],b));
        return max(f(i+1,n,nums,curr,b),f(i+1,n,nums,curr*nums[i],1));
    }
    long long maxStrength(vector<int>& nums) {
        return f(0,nums.size(),nums,1,0);
    }
};