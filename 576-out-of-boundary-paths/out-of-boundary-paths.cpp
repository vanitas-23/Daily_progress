class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    int f(int m, int n, int maxMove,int i,int j,int* dr,int* dc){
        if(i<0 || i>=m || j<0 || j>=n)
         return 1;
        if(!maxMove)
        return 0;
        if(dp[i][j][maxMove]!=-1)
        return dp[i][j][maxMove];
        long ans=0;
        for(int x=0;x<4;x++){
            int row=i+dr[x];
            int col=j+dc[x];
            ans+=f(m,n,maxMove-1,row,col,dr,dc);
        }
        return dp[i][j][maxMove]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        memset(dp,-1,sizeof(dp));
        return f(m,n,maxMove,startRow,startColumn,dr,dc);
    }
};