//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int f(int* A,int N,int i,vector<int>& dp){
        if(i==N-1)
        return 1;
        
        if(A[i]==0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=0;
        for(int j=1;j<=A[i];j++)
            if(!ans)
            ans|=f(A,N,i+j,dp);
            else
            return dp[i]=ans;
        
        return dp[i]=ans;
    }
    int canReach(int A[], int N) {
    vector<int>dp(N,-1);
        return f(A,N,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends