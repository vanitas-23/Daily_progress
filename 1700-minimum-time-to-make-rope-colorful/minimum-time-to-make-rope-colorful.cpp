class Solution {
public:
  int minimum_time(string &colors,vector<int>&time,int idx,char  prev,vector<vector<int>>&dp)
  {
   if(idx>=colors.size())
   {
     return 0;
   }
 
    if(dp[idx][prev-'a']!=-1)
    {
      return dp[idx][prev-'a'];
    }
   
  int pick=time[idx]+minimum_time(colors,time,idx+1,prev,dp);
   
    
    int not_pick=INT_MAX;
 
    if(colors[idx]!=prev)
    {
       
      not_pick=0+minimum_time(colors,time,idx+1,colors[idx],dp);
     
    }

    return dp[idx][prev-'a']=min(pick,not_pick);
  }
    int minCost(string colors, vector<int>&time) {
        
      vector<vector<int>>dp(colors.size()+10,vector<int>(27,-1));
    
      return minimum_time(colors,time,0,'{',dp);
    }
};