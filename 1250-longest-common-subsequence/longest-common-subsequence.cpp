class Solution {
public:
    int f(int i,int j,int n,int m,string& s,string& t,vector<vector<int>>& dp)
{
    if(i==n || j==m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i]==t[j])
    return dp[i][j]= 1+f(i+1,j+1,n,m,s,t,dp);
    return dp[i][j]= max(f(i+1,j,n,m,s,t,dp),f(i,j+1,n,m,s,t,dp));
}
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return  f(0,0,n,m,s,t,dp);
    }
};