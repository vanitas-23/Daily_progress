class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pr, vector<vector<int>>& q) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(int i=0;i<pr.size();i++)
        mat[pr[i][0]][pr[i][1]]=1;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
        if(mat[j][i] && mat[i][k]) mat[j][k]=1;
        vector<bool>ans;
        for(auto i:q) ans.push_back(mat[i[0]][i[1]]);
        return ans;
    }
};