#define ll long long
class Solution {
public:
    bool f(ll mid,ll k,vector<int>& c)
    {
        for(auto i:c)
        {
            k-=(i/mid);
            if(k<=0)
            return 1;
        }
        return 0;
    }
    int maximumCandies(vector<int>& c, long long k) {
        ll l=1;
        ll r=1e7;
        ll ans=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(f(mid,k,c))
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