class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
            
        vector<int> row(n,0);
        vector<int> col(m,0);
        
        int cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    if(row[i]>1 || col[j]>1)
                        cnt++;
        return cnt;
    }
};