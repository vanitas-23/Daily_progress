class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
            continue;
            int r=i;
            int c=j;
            while(r<n && grid[r][j]==1)
            r++;
            while(c<m && grid[i][c]==1)
            c++;
             ans.push_back({i,j,r-1,c-1});
            
            for(int x=i;x<r;x++)
            for(int y=j;y<c;y++)
            grid[x][y]=0;
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<m;j++)
            //     cout<<grid[i][j]<<" ";
            //     cout<<endl;
            // }
        }
        return ans;
    }
};