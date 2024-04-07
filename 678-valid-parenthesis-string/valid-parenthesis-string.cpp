class Solution {
public:
    bool f(int i,int n,string s,int val,vector<vector<int>>& dp)
    {
        if(i==n)
        return val==0;
        if(dp[i][val+n]!=-1)
        return dp[i][val+n];
        if(val<0 || val>n/2)
        return dp[i][val+n]=false;
        if(s[i]=='(')
        return dp[i][val+n]=f(i+1,n,s,val+1,dp);
        else if(s[i]==')')
        return dp[i][val+n]=f(i+1,n,s,val-1,dp);

        return dp[i][val+n]=(f(i+1,n,s,val,dp) || f(i+1,n,s,val-1,dp) || f(i+1,n,s,val+1,dp));
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(2*n+1,-1));
        return f(0,s.size(),s,0,dp);
    }
};