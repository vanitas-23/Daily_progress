#define ll long long 
class Solution {
public:
    ll f(int i,int n,int isA,vector<int>& A, vector<int>& B,vector<vector<ll>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][isA]!=-1)
        return dp[i][isA];
        ll ns=0;
        if(isA)
        ns=A[i]+f(i+1,n,isA,A,B,dp);
        else
        ns=B[i]+f(i+1,n,isA,A,B,dp);
        ll s=f(i+1,n,!isA,A,B,dp);
        return dp[i][isA]=max(ns,s);
    }
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<vector<ll>>dp(n,vector<ll>(2,-1));
        return max(f(0,n,0,A,B,dp),f(0,n,1,A,B,dp));
    }
};