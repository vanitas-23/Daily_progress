class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(grid[i][j]==0)
        return 0;
        int ans=grid[i][j];
        grid[i][j]=0;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        for(int k=0;k<4;k++)
        {
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]>0)
            ans+=dfs(r,c,n,m,grid);
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        ans=max(ans,dfs(i,j,n,m,grid));
        return ans;
    }
};