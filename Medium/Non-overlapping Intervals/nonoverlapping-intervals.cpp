//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int n, vector<vector<int>> &intervals) {
        // code here
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        temp.push_back({intervals[i][0],intervals[i][1]}) ;
        
        sort(temp.begin(),temp.end());
        int count=0;
        int end=temp[0].second;
        for(int i=1;i<n;i++)
        {
            if(temp[i].first>=end)
            {
                end=temp[i].second;
            }
            else
            {
                count++;
                if(temp[i].second<end)
                end=temp[i].second;
            }
        }
        return count ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends