class Solution {
public:
    int f(vector<int>& nums,int tar,int ind,int n, map<pair<int, int>, int>& dp){
        if(ind==n){
           return tar==0;
        }
        if(dp.count({ind, tar}))
        return dp[{ind,tar}];
        int pos=f(nums,tar+nums[ind],ind+1,n,dp);
        int neg=f(nums,tar-nums[ind],ind+1,n,dp);
        return dp[{ind,tar}]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int, int>, int> dp;
        return f(nums,target,0,n,dp);
    }
};