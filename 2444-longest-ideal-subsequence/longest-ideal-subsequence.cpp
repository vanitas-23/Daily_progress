class Solution {
public:
    int fn(int ind,int prev,string &s,int &k, vector<vector<int>>&dp)
    {
        if(ind>=s.size())
            return 0;
        
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        
        
        int taken=0;
        
        if(prev==-1) 
        {
            taken=1+fn(ind+1,s[ind]-'a',s,k,dp);
        }
        else {
            int val=s[ind]-'a';
            
            if(abs(val-prev)<=k)
                taken=1+fn(ind+1,s[ind]-'a',s,k,dp);
        }
        
        int nonTaken=fn(ind+1,prev,s,k,dp);
        
        return dp[ind][prev+1]= max(taken,nonTaken);
        
    }
    int longestIdealString(string s, int k) {
     vector<vector<int>>dp(s.size(),vector<int>(28,-1));
                return fn(0,-1,s,k,dp);
       
    }
};