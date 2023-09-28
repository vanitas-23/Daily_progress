//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>> &grid,int* dx,int* dy,int n,int m){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
            dfs(x,y,grid,dx,dy,n,m);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
            dfs(i,0,grid,dx,dy,n,m);
            if(grid[i][m-1]==1)
            dfs(i,m-1,grid,dx,dy,n,m);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)
            dfs(0,i,grid,dx,dy,n,m);
            if(grid[n-1][i]==1)
            dfs(n-1,i,grid,dx,dy,n,m);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==1)
        cnt++;
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends