class Solution {
public:
    int helper(vector<vector<int>> &usez,vector<vector<int>> &usem,int i,int n){
        if(i>=n){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=0;k<usem.size();k++){
            if(usem[k][2]>1){
                usem[k][2]--;
                ans=min(ans,abs(usez[i][0]-usem[k][0])+abs(usez[i][1]-usem[k][1])+helper(usez,usem,i+1,n));
                usem[k][2]++;
            }
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> usez;
        vector<vector<int>> usem;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    usez.push_back({i,j});
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]>1){
                    usem.push_back({i,j,grid[i][j]});
                }
            }
        }
        return helper(usez,usem,0,usez.size());
    }
};