class Solution {
public:
    int f(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>& dp){
           if(j1<0 || j1>(grid[0].size()-1) || j2<0 || j2>(grid[0].size()-1))
           return 0;
           if(i==grid.size()-1){
                 if(j1==j2)
                 return grid[i][j1];
                 return grid[i][j1]+grid[i][j2];
           }
           if(dp[i][j1][j2]!=-1)
           return dp[i][j1][j2];
           int maxx=INT_MIN;
           for(int k=-1;k<=1;k++){
               for(int j=-1;j<=1;j++){
                   int val=grid[i][j1]+grid[i][j2];
                   if(j1==j2)
                   val=grid[i][j1];

                   val+=f(grid,i+1,j1+k,j2+j,dp);
                   maxx=max(maxx,val);
               }
           }
           return dp[i][j1][j2]=maxx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(grid,0,0,grid[0].size()-1,dp);
        
    }
};