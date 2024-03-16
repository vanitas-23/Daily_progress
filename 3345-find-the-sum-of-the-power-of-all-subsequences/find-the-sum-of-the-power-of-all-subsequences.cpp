#include <vector>
#include <unordered_map>
#include <utility>
#define ll long long
using namespace std;

class Solution {
public:
    ll m = 1e9 + 7;
    
    unordered_map<int, int> mp;

    
    ll mod_expo(ll a, ll b) {
        ll ans = 1;
        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % m;
            b = b >> 1;
            a = (a * a) % m;
        }
        return ans;
    }

    ll f(int i, vector<int>& nums, int k, int c, int n,vector<vector<vector<int>>>& dp) {
        if(k==0)
        return mod_expo(2,n-c);
        if(i>=n || k<0)
        return 0;
        if(dp[i][k][c]!=-1)
        return dp[i][k][c];
        ll ntaken=f(i+1,nums,k,c,n,dp);
        ll taken=f(i+1,nums,k-nums[i],c+1,n,dp);
        return dp[i][k][c]=(ntaken+taken)%m;
    }

    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(n+1,-1)));
        return f(0, nums, k, 0, n,dp);
    }
};
