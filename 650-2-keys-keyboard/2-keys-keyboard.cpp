class Solution {
public:
    int f(int curr,int n,int last,vector<vector<int>>& dp)
    {
       // cout<<curr<<" "<<n<<" "<<last<<endl;
        if(curr==n)
        return 0;
        if(curr>n)
        return 1e9;
        if(dp[curr][last]!=-1)
        return dp[curr][last];
        int nt=1e9;
        if(last!=0)
        nt=1+f(curr+last,n,last,dp);
        int t = 2+f(curr*2,n,curr,dp);
        return dp[curr][last]=min(t,nt);
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,0,dp);
    }
};