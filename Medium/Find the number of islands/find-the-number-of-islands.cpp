//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(int i,int j,int a,int b,vector<vector<char>>& grid){
        if(i>=0 && i<a && j>=0 && j<b && grid[i][j]=='1')
        return true;
        return false;
    }
    void recCall(int i,int j,int a,int b,vector<vector<char>>& grid){
             grid[i][j]='0';
             if(isValid(i-1,j,a,b,grid))
            recCall(i-1,j,a,b,grid);
              if(isValid(i+1,j,a,b,grid))
             recCall(i+1,j,a,b,grid);
              if(isValid(i,j-1,a,b,grid))
             recCall(i,j-1,a,b,grid);
             if(isValid(i,j+1,a,b,grid))
             recCall(i,j+1,a,b,grid);
             if(isValid(i-1,j-1,a,b,grid))
            recCall(i-1,j-1,a,b,grid);
            if(isValid(i-1,j+1,a,b,grid))
            recCall(i-1,j+1,a,b,grid);
            if(isValid(i+1,j+1,a,b,grid))
            recCall(i+1,j+1,a,b,grid);
            if(isValid(i+1,j-1,a,b,grid))
            recCall(i+1,j-1,a,b,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int a=grid.size();
        int b=grid[0].size();
        int res=0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(grid[i][j]=='1'){
                    res++;
                    recCall(i,j,a,b,grid);
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends