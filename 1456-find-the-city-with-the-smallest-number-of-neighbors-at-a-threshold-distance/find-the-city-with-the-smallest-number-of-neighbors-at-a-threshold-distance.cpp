class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<int>>grid(n,vector<int>(n,1e9));
        for(auto i:edges)
        {
            grid[i[0]][i[1]]=i[2];
            grid[i[1]][i[0]]=i[2];
            grid[i[0]][i[0]]=0;
            grid[i[1]][i[1]]=0;
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
        if(grid[j][k]>grid[j][i]+grid[i][k])
        grid[j][k]=grid[j][i]+grid[i][k];

        int ans=-1;
        int mn=1e9;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            if(grid[i][j]<=thres)
            {
                temp++;
            }
           // cout<<i<<" "<<temp<<endl;
            if(mn>=temp)
            {
                mn=temp;
                ans=i;
            }
        }
        return ans;
    }
};