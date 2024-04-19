class Solution {
public:
    bool isValid(int i,int j,int a,int b,vector<vector<char>>& grid){
        if(i>=0 && i<a && j>=0 && j<b && grid[i][j]=='1')
        return true;
        return false;
    }
    void recCall(int i,int j,int a,int b,vector<vector<char>>& grid){
             grid[i][j]='0';
             if(isValid(i-1,j,a,b,grid))
            recCall(i-1,j,a,b,grid);
              if(isValid(i+1,j,a,b,grid))
     recCall(i+1,j,a,b,grid);
              if(isValid(i,j-1,a,b,grid))
             recCall(i,j-1,a,b,grid);
             if(isValid(i,j+1,a,b,grid))
             recCall(i,j+1,a,b,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int a=grid.size();
        int b=grid[0].size();
        int res=0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(grid[i][j]=='1'){
                    res++;
                    recCall(i,j,a,b,grid);
                }
            }
        }
        return res;
    }
};