//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
       int solve(int i,int n,int sum,int total,int arr[],vector<vector<int>>&dp){
        if(i==n) return abs(total-(2*sum));
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nt = solve(i+1,n,sum,total,arr,dp);
        int pk = solve(i+1,n,sum+arr[i],total,arr,dp);
        return dp[i][sum] = min(nt,pk);
    }
int minDifference(int arr[], int n)  { 
    int total = 0;
    for(int i=0;i<n;i++) total+=arr[i];
    vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
    return solve(0,n,0,total,arr,dp);
} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends