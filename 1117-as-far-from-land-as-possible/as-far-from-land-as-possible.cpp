class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>>water,land;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j])
        land.push_back({i,j});
        else
        water.push_back({i,j});

        int ans=-1;
        for(auto i:water)
        {
            int temp=1e9;
            for(auto j:land)
            if(abs(i.first-j.first)+abs(i.second-j.second)<temp)
            {
                temp=abs(i.first-j.first)+abs(i.second-j.second);
            }
            ans=max(ans,temp);
        }
        return ans==1e9?-1:ans;
    }
};