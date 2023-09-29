class Solution {
public:
    int parent[40005];
    int rank[40005];

    void init(){
        for(int i=0; i<40005; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionf(int u, int v){
        int up = findParent(u);
        int vp = findParent(v);

        if(up == vp)
            return;
        if(rank[up] == rank[vp]){
            parent[up] = vp;
            rank[vp]++;
        } else if (rank[up] > rank[vp]){
            parent[vp] = up;
        } else {
            parent[up] = vp;
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        init();
        rank[40004]= INT_MAX;

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O')
                unionf(i*n ,40004);
            if(board[i][n-1] == 'O')
                unionf(i*n+n-1, 40004);
        }
        for(int j=1; j<n-1; j++){
            if(board[0][j] == 'O')
                unionf(j, 40004);
            if(board[m-1][j] == 'O')
                unionf(n*(m-1)+j,40004);
        }
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(board[i][j] == 'X')
                    continue;
                if(board[i-1][j] == 'O')
                    unionf((i-1)*n+j, i*n+j);
                if(board[i+1][j] == 'O')
                    unionf((i+1)*n+j, i*n+j);
                if(board[i][j-1] == 'O')
                    unionf((i)*n+j-1, i*n+j);
                if(board[i][j+1] == 'O')
                    unionf((i)*n+j+1, i*n+j);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && findParent(i*n+j) != 40004)
                    board[i][j] = 'X';
            }
        }
    }
};