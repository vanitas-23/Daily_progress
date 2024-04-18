class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    void f(int i,int j,vector<vector<int>>& grid)
    {
        grid[i][j]=-1;
        for(int k=0;k<4;k++)
        {
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[i][j]==1)
            f(r,c,grid);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j])
            f(i,j,grid);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(grid[i][j]==-1)
            {
                int sds=0;
                if(i+1>=n)
                sds++;
                else if(grid[i+1][j]==0)
                sds++;
                if(i-1<0)
                sds++;
                else if(grid[i-1][j]==0)
                sds++;
                if(j+1>=m)
                sds++;
                else if(grid[i][j+1]==0)
                sds++;
                if(j-1<0)
                sds++;
                else if(grid[i][j-1]==0)
                sds++;
                cnt+=sds;
            }
        
       return cnt;
    }
};