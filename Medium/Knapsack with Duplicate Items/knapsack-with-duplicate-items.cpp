//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int N,int W,int* val,int* wt,int i, vector<vector<int>>& dp){
        if(i==N)
        return 0;
        if(dp[i][W]!=-1)
        return dp[i][W];
        int ntaken=f(N,W,val,wt,i+1,dp);
        int taken=0;
        if(wt[i]<=W)
        taken=val[i]+f(N,W-wt[i],val,wt,i,dp);
        
        return dp[i][W]=max(taken,ntaken);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return f(N,W,val,wt,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends