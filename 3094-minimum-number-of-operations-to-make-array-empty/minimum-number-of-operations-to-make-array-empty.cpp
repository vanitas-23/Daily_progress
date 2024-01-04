class Solution {
public:
    int f(int i,vector<int>& dp){
        if(i==0)
        return 0;
        if(i<0)
        return 1e9;
        if(dp[i]!=-1)
        return dp[i];
        int tw=1+f(i-2,dp);
        int th=1+f(i-3,dp);

        return dp[i]=min(tw,th);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        f(n,dp);
        sort(nums.begin(),nums.end());

        int cnt=0;
        int temp=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
            temp++;
            else{
                if(temp==1)
                return -1;           
                cnt+=dp[temp];
                temp=1;
            }
        }
        if(temp==1)
        return -1;
        return cnt+dp[temp];
    }
};