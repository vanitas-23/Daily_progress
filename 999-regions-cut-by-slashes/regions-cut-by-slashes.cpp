class Solution {
public:
    void dfs(int i,int j,int n,vector<vector<int>>& nn)
    {
        vector<int>rx={-1,1,0,0};
        vector<int>ry={0,0,1,-1};
        nn[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int r=i+rx[k];
            int c=j+ry[k];
            if(r>=0 && r<n && c>=0 && c<n && nn[r][c]==0)
            dfs(r,c,n,nn);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>nn(3*n,vector<int>(3*n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='\\')
                {
                    nn[i*3][j*3]=1;
                    nn[i*3+1][j*3+1]=1;
                    nn[i*3+2][j*3+2]=1;
                }
                else if(grid[i][j]=='/')
                {
                    nn[i*3][j*3+2]=1;
                    nn[i*3+1][j*3+1]=1;
                    nn[i*3+2][j*3]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {
                if(nn[i][j]==0)
                {
                    ans++;
                    dfs(i,j,3*n,nn);
                }
            }
        }
        return ans;
    }
};