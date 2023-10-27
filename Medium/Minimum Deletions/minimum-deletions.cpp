//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        string t=s;
        reverse(s.begin(),s.end());
         vector<vector<int>>dp(t.size()+1,vector<int>(s.size()+1,1));
        
        for(int i=0;i<=t.size();i++)
            dp[i][0]=0;
         for(int i=0;i<=s.size();i++)
            dp[0][i]=0;
        for(int i=1;i<=t.size();i++)
            for(int j=1;j<=s.size();j++)
                if(s[j-1]==t[i-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        return s.size()-dp[t.size()][s.size()];
    } 
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends