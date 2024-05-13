class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;j++)
                grid[i][j]=!grid[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            int one=0;
            for(int j=0;j<n;j++)
            one+=grid[j][i];
            if(one<n-one)
            for(int j=0;j<n;j++)
            grid[j][i]=!grid[j][i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int curr=0;
            int x=0;
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j])
                curr|=(1<<x);
                x++;
            }
            ans+=curr;
        }
        
        return ans;
    }
};