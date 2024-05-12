class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>res(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++)
        for(int j=0;j<n-2;j++)
        {
            int mx=grid[i][j];
            mx=max(mx,grid[i+1][j]);
            mx=max(mx,grid[i+2][j]);
            mx=max(mx,grid[i][j+1]);
            mx=max(mx,grid[i+1][j+1]);
            mx=max(mx,grid[i+2][j+1]);
            mx=max(mx,grid[i][j+2]);
            mx=max(mx,grid[i+1][j+2]);
            mx=max(mx,grid[i+2][j+2]);
            res[i][j]=mx;
        }
        return res;
    }
};