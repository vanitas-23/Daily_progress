class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]==0){
                for(int k=j+1;k<m;k++){
                    if(mat[i][k]==0)
                    break;
                    else
                    mat[i][k]=1e9;
                }
                for(int k=j-1;k>=0;k--){
                    if(mat[i][k]==0)
                    break;
                    else
                    mat[i][k]=1e9;
                }
                for(int k=i+1;k<n;k++){
                    if(mat[k][j]==0)
                    break;
                    else
                    mat[k][j]=1e9;
                }
                for(int k=i-1;k>=0;k--){
                    if(mat[k][j]==0)
                    break;
                    else
                    mat[k][j]=1e9;
                }
                
            }
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(mat[i][j]==1e9)
            mat[i][j]=0;
        
    }
};