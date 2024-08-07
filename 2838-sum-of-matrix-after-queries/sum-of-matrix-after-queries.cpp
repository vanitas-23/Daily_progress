class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans=0;
        set<int>row;
        set<int>col;
        int m=queries.size();
        for(int i=m-1;i>=0;i--)
        {
            if(queries[i][0]==1)
            {
                if(col.find(queries[i][1])!=col.end())
                {
                    continue;
                }
                int x=n-row.size();
                ans+=x*1ll*queries[i][2];
                col.insert(queries[i][1]);
            }
            else
            {
                if(row.find(queries[i][1])!=row.end())
                {
                    continue;
                }
                int x=n-col.size();
                ans+=x*1ll*queries[i][2];
                row.insert(queries[i][1]);
            }
        }
        return ans;
    }
};