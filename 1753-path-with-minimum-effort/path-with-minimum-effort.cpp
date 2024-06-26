class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& he) {
        int n=he.size();
        int m=he[0].size();

        vector<vector<int>>vis(n,vector<int>(m,-1));
        vis[0][0]=he[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            vector<int>dx={0,0,1,-1};
            vector<int>dy={1,-1,0,0};
            if(x.second.first==n-1 && x.second.second==m-1)
            return x.first;
            for(int i=0;i<4;i++)
            {
                int r=x.second.first+dx[i];
                int c=x.second.second+dy[i];
                if(r<0 || r>=n || c<0 || c>=m)
                continue;
                if(vis[r][c]==-1){
                vis[r][c]=max(x.first,abs(he[r][c]-he[x.second.first][x.second.second]));
                pq.push({vis[r][c],{r,c}});
                }
                else
                {
                    if(vis[r][c]>max(x.first,abs(he[r][c]-he[x.second.first][x.second.second])))
                    {
                        vis[r][c]=max(x.first,abs(he[r][c]-he[x.second.first][x.second.second]));
                        pq.push({vis[r][c],{r,c}});
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }
};