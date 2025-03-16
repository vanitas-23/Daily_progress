#define ll long long
class Solution {
public:
    bool f(ll mid,vector<int>& ranks, int cars)
    {
        for(auto i:ranks)
        {
            ll x=mid/i;
            x=sqrtl(x);
            //cout<<i<<" "<<x<<endl;
            cars-=x;
            if(cars<=0)
            return 1;
        }
        return 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l=0;
        ll r=1e18;
        ll ans=r;
        while(l<=r)
        {
            ll mid=r-(r-l)/2;
            if(f(mid,ranks,cars))
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