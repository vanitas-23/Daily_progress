#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<ll>>prf(n,vector<ll>(m));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        prf[i][j]=grid[i][j];
        auto suff=prf;
        for(int i=1;i<m;i++)
        {
        prf[0][i]+=prf[0][i-1];
        prf[1][i]+=prf[1][i-1];
        }

        for(int i=m-2;i>=0;i--)
        {
        suff[0][i]+=suff[0][i+1];
        suff[1][i]+=suff[1][i+1];
        }
        ll ans=1e18;
        for(int i=0;i<m;i++)
        {
            ll x=0,y=0;
            if(i-1>=0)
            x=prf[1][i-1];
            if(i+1<m)
            y=suff[0][i+1];
            //cout<<x<<" "<<y<<endl;
            ans=min(ans,max(x,y));
        }
        //cout<<ans;
        
        return ans;
    }
};