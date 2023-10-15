class Solution {
public:
int m=1e9+7;
    int f(int steps,int arrLen,int pos,vector<vector<int>>& dp){
        if(pos>=arrLen || pos<0)
        return 0;
        if(steps==0){
            if(pos==0)
            return 1;
            return 0;
        }
        if(dp[steps][pos]!=-1)
        return dp[steps][pos];
        return dp[steps][pos]=(f(steps-1,arrLen,pos,dp)*1LL%m+f(steps-1,arrLen,pos+1,dp)%m+          f(steps-1,arrLen,pos-1,dp)%m)%m;


    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(steps+1,vector<int>(steps+1,-1));
        return f(steps,arrLen,0,dp);
    }
};