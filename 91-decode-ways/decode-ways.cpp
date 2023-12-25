class Solution {
public:
    int f(int i,int n,string s,vector<int>& dp){
        if(i==n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        int a1=0,a2=0;
        if(s[i]=='0')
        return dp[i]=0;
         a1=f(i+1,n,s,dp);
        if(i+1<n){
                if(s[i]=='1')
                a2=f(i+2,n,s,dp);
                else if(s[i]=='2' && s[i+1]<='6')
                a2=f(i+2,n,s,dp);
        }
        return dp[i]=a1+a2;
    }
        int numDecodings(string s) {
            vector<int>dp(s.size(),-1);
        return f(0,s.size(),s,dp);
    }
};