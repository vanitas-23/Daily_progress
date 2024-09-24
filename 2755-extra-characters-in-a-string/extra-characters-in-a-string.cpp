
class Solution {
public:
    map<string,int>mp;
    int f(int i,int n,string s,vector<int>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int nt=1+f(i+1,n,s,dp);
        string temp="";
        for(int j=i;j<n;j++)
        {
            temp+=s[j];
            if(mp.find(temp)!=mp.end())
            nt=min(nt,f(j+1,n,s,dp));
            else
            nt=min(nt,j-i+1+f(j+1,n,s,dp));
        }
        return dp[i]=nt;
    }
    int minExtraChar(string s, vector<string>& dic) {
        
        for(auto i:dic)
        mp[i]++;
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp);
    }
};