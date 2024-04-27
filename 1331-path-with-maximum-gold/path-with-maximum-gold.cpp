class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        int temp=grid[i][j];
        grid[i][j]=0;
        int ans=0;
        for(int x=0;x<4;x++)
        {
            int r=i+dx[x];
            int c=j+dy[x];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]!=0)
            ans=max(ans,dfs(r,c,n,m,grid));
        }
        grid[i][j]=temp;
        ans+=temp;
        //cout<<i<<" "<<j<<" "<<ans<<endl;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
            continue;
            ans=max(ans,dfs(i,j,n,m,grid));
        }
        return ans;
    }
};