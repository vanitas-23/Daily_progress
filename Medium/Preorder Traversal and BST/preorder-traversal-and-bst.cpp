//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int n) {
          stack<int> s;
        int k = 0;
        for(int i = 0; i < n; i++)
        
            if(s.empty() || arr[i] < s.top())
            {
                if(k > arr[i])
                    return 0;
                s.push(arr[i]);
            }
            else
            {
                while(!s.empty() && s.top() < arr[i])
                {
                    k = s.top();
                    s.pop();
                }
                s.push(arr[i]);
            }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends