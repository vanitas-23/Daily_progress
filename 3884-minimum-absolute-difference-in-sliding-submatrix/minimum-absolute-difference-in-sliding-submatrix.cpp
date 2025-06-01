class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<n-k+1;i++)
        {
            for(int j=0;j<m-k+1;j++)
            {
                vector<int>temp;
                for(int x=i;x<i+k;x++)
                for(int y=j;y<j+k;y++)
                temp.push_back(grid[x][y]);
                sort(temp.begin(),temp.end());
                int ans=1e9;
                for(int x=1;x<temp.size();x++)
                {
                    if(temp[x]==temp[x-1]) continue;
                    ans=min(ans,temp[x]-temp[x-1]);
                }
                if(ans==1e9)
                ans=0;
                res[i][j]=ans;
            //     for(auto i:temp)
            //     cout<<i<<" ";
            //     cout<<endl;
            }
        }
        return res;
    }
};