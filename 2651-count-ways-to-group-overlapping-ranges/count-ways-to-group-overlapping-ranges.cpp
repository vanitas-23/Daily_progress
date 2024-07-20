#define ll long long
class Solution {
public:
    ll mod_expo(ll a,ll b)
{
    int m=1e9+7;
    ll ans = 1;
    while(b>0){
        if(b&1)
        ans = (ans*a)%m;
        b = b >> 1;
        a = (a * a)%m;
    }
    return ans%m;
}
    int countWays(vector<vector<int>>& ranges) {
        map<int,int>mp;
        for(auto i:ranges)
        {
            mp[i[0]]++;
            mp[i[1]]--;
        }
        int grps=0;
        int curr=0;
        for(auto i:mp)
        {
            curr+=i.second;
            if(curr==0)
            grps++;
        }
        // cout<<grps;
        return mod_expo(2,grps);
    }
};