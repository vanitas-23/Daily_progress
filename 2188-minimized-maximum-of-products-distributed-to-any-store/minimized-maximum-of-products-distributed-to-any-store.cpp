#define ll int
class Solution {
public:
    bool f(ll mid,int n,vector<int>& q)
    {
        ll sum=0;
        for(auto i:q)
        sum+=ceil(i*1.0/mid);
        return sum<=n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1;
        ll r=*max_element(q.begin(),q.end());
        ll ans=r;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(f(mid,n,q))
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};