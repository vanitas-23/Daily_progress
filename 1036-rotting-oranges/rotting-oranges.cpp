class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j]==2 || grid[i][j]==1) cnt++;
            }
        }
        if(cnt==0)
        return 0;
        int ans=0;
        while(!q.empty())
        {
            int mm=q.size();
            for(int i=0;i<mm;i++)
            {
                auto f=q.front();
                for(int j=0;j<4;j++)
                {
                    int new_x=f.first+dx[j];
                    int new_y=f.second+dy[j];
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]==1)
                    {
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                    }
                }
                q.pop();
            }
            ans++;   
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            return -1;
        }
        return ans-1;
    }
};