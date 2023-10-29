//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
/*
//User function Template for C++

class Solution{
public:
    int f(int j,int pre,vector<vector<int>> &costs,int n,int m,vector<vector<int>>& dp){
        if(j==n)
        return 0;
        if(dp[j][pre+1]!=-1)
        return dp[j][pre+1];
        int ans=1e9;
        for(int i=0;i<m;i++)
        if(i!=pre)
        ans=min(ans,costs[j][i]+f(j+1,i,costs,n,m,dp));
        
        return dp[j][pre+1]=ans;
    }
    int minCost(vector<vector<int>> &costs) {
        int n=costs.size();
        int m=costs[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        int ans=f(0,-1,costs,n,m,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};*/
class Solution{   
public:
int f(int j,int pre,vector<vector<int>> &costs,int n,int m,vector<vector<int>>& dp){
        if(j==n)
        return 0;
        if(dp[j][pre+1]!=-1)
        return dp[j][pre+1];
        int ans=1e9;
        for(int i=0;i<m;i++)
        if(i!=pre)
        ans=min(ans,costs[j][i]+f(j+1,i,costs,n,m,dp));
        
        return dp[j][pre+1]=ans;
    }
    int minCost(vector<vector<int>> &costs, int N) {
        // Write your code here.
        int n=costs.size();
        int m=costs[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        int ans=f(0,-1,costs,n,m,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends