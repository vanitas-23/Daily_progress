class Solution {
public:
    bool f(int n,int k,int budget,vector<vector<int>>& com,vector<int>& stock, vector<int>& cost,int m)
    {
        for(int i=0;i<k;i++)
        {
            long long temp=budget;
            for(int j=0;j<n;j++)
            {
                if(com[i][j]*1ll*m>stock[j])
                {
                    temp-=(com[i][j]*1LL*m-stock[j])*cost[j];
                }
            }
            if(temp>=0)
            return 1;
        }
        return 0;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& com, vector<int>& stock, vector<int>& cost) {
        int l=0;
        int r=1e9;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            //cout<<mid<<" ";
            if(f(n,k,budget,com,stock,cost,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return ans;
    }
};