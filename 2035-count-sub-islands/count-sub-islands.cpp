class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        if(grid1[i][j]!=1)
        return 0;
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,1,-1};
        grid2[i][j]=0; bool x=1;
        for(int k=0;k<4;k++)
        {
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && r<n && c>=0 && c<m && grid2[r][c])
            x&=dfs(r,c,n,m,grid1,grid2);
        }
        return x;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid2[i][j])
            ans+=dfs(i,j,n,m,grid1,grid2);
        }
        return ans;
    }
};
static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();