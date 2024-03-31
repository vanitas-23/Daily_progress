class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])
        return -1;
        int ans=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        int n=grid.size();
        vector<int>dx={1,-1,0,0,-1,-1,1,1};
        vector<int>dy={0,0,1,-1,-1,1,-1,1};
        while(!q.empty())
        {
            int m=q.size();
            ans++;
            for(int i=0;i<m;i++)
            {
                auto x=q.front();
                q.pop();
                if(x.first==n-1 && x.second==n-1)
                return ans;
                for(int k=0;k<8;k++)
                {
                    int r = x.first+dx[k];
                    int c= x.second + dy[k];
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0)
                    q.push({r,c}),grid[r][c]=1;
                }
            }
            
        }
        return -1;
    }
};