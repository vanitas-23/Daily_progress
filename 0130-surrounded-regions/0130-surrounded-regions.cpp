class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,int* dx,int* dy,int n,int m){
        board[i][j]='m';
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && board[x][y]=='O')
            dfs(x,y,board,dx,dy,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
            dfs(i,0,board,dx,dy,n,m);
            if(board[i][m-1]=='O')
            dfs(i,m-1,board,dx,dy,n,m);
        }

        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
            dfs(0,i,board,dx,dy,n,m);
            if(board[n-1][i]=='O')
            dfs(n-1,i,board,dx,dy,n,m);
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(board[i][j]=='m')
        board[i][j]='O';
        else
        board[i][j]='X';
    }
};