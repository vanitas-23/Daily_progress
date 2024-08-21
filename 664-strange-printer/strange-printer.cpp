
class Solution {
public:
    int solve(int l, int r, string& s,map<pair<int,int>,int>& dp){
        if(l == r)
            return 1;
        else if(l > r)
            return 0;
        if(dp.count({l,r})!=0)
        return dp[{l,r}];
        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;
        if(i == r+1)
            return 1;
        int normal = 1 + solve(i,r,s,dp);
        int aage_ka = INT_MAX;
        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = solve(i,j-1,s,dp) + solve(j,r,s,dp);
                
                aage_ka = min(aage_ka, x);
            }
        }

        return dp[{l,r}] = min(aage_ka, normal);
    }

    int strangePrinter(string s) {
        int n = s.length() ;
        map<pair<int,int>,int>dp;
        return solve(0, n-1, s,dp);
    }
};
