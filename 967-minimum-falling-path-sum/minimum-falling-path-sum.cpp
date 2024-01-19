class Solution {
public:
    int f(vector<vector<int>>& matrix,int n,int row,int col,vector<vector<int>>& dp){
       if(col<0 || col>=n)
       return 1e9;
       if(row==0)
       return matrix[row][col];
        if(dp[row][col]!=-1e9)
        return dp[row][col];
        int up = matrix[row][col] + f(matrix,n,row-1,col,dp);
        int leftDiagonal = matrix[row][col] + f(matrix,n,row-1,col-1,dp);
        int rightDiagonal = matrix[row][col] + f(matrix,n,row-1,col+1,dp);
        return dp[row][col]=min(rightDiagonal,min(leftDiagonal,up));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
       
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
       int ans=INT_MAX;
       for(int i=0;i<n;i++)
        ans=min(ans,f(matrix,n,n-1,i,dp));
       
       return ans;
    }
};