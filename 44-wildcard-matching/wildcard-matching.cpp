class Solution {
public:
    bool ias(string & S1, int i) {
  for (int j = 0; j <= i; j++) {
    if (S1[j] != '*')
      return false;
  }
  return true;
}
    bool f(string& wild,string& pattern,int i,int j,vector<vector<int>>& dp){
        if(i<0)
        return j<0; 
        if(j<0)
        return ias(wild,i);
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(wild[i]==pattern[j])
            return dp[i][j]= f(wild,pattern,i-1,j-1,dp);
            
        if(wild[i]=='?')
            return dp[i][j]=f(wild,pattern,i-1,j-1,dp);
            
        if(wild[i]=='*')
            return dp[i][j]=f(wild,pattern,i-1,j,dp) | f(wild,pattern,i,j-1,dp);
            
        return dp[i][j]= 0;
        
    }
    bool isMatch(string pattern, string wild) {
        int n=wild.size();
        int m=pattern.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(wild,pattern,n-1,m-1,dp);
    }
};