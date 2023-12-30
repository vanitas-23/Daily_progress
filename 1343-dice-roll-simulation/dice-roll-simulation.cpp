class Solution {
public:

    #define ll long long

    int n;
    vector<int>a;
    ll mod=1e9+7;

    ll dp[5001][7][16];

    ll f(int i, int last, int cnt){
        if(i==n)return 1;

        if(dp[i][last][cnt]!=-1) return dp[i][last][cnt];

        ll ans=0;

        for(int x=1;x<=6;x++){
            if(x==last){
                if(cnt+1<=a[x-1]) // we can still include last
                    ans+=f(i+1,last,cnt+1);
            }
            else{
                ans+=f(i+1,x,1);
            }
        }

        return dp[i][last][cnt]=ans%mod;
    }

    int dieSimulator(int _n, vector<int>& _a) {
        a=_a; n=_n;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0);
    }
};