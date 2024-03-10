class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0])
            continue;
            for(int j=0;j<m;j++)
            grid[i][j]=!grid[i][j];
        }
        for(int j=0;j<m;j++)
        {
            int zer=0;
            int on=0;
            for(int i=0;i<n;i++)
            if(grid[i][j])
            on++;
            else
            zer++;
            if(zer<on)
            continue;
            for(int i=0;i<n;i++)
            grid[i][j]=!grid[i][j];
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            if(grid[i][j])
            ans+=(1<<(m-1-j));
        }
        return ans;
    }
};