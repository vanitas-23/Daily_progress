class Solution {
public:
    int f(int n , vector<int> &v , vector<int> &dp){
        if(n==0 || n==1) return v[n];
        if(dp[n] != -1) return dp[n];
        int notpick =v[n] + f(n-1,v,dp) ;
        int pick = INT_MAX;
        if(n>1){
            pick =  v[n] +  f(n-2,v,dp);
        }
        return dp[n] =  min(pick,notpick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min( f(n-1,cost,dp) , f(n-2,cost,dp) );
    }
};