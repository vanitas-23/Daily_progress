class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    bool dfs(int i,int j,vector<vector<char>>& board,int k ,string word,int n,int m,vector<vector<int>>& vis)
    {
        if(word[k]!=board[i][j])
        return false;
        vis[i][j]=1;
        
        //cout<<i<<" "<<j<<endl;
         if(k==word.size()-1)
        {
            cout<<word[k]<<" ";
            return true;
        }
        for(int x=0;x<4;x++)
        {
            int r = i+dx[x];
            int c = j+dy[x];
            
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c]) 
            if(dfs(r,c,board,k+1,word,n,m,vis))
            return true;
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            vector<vector<int>>vis(n,vector<int>(m));
            if(dfs(i,j,board,0,word,n,m,vis))
            return true;
        }
        return false;
    }
};