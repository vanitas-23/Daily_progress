class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        mp[mat[i][j]]={i,j};
        vector<int>xx(n);
        vector<int>yy(m);
        for(int i=0;i<arr.size();i++)
        {
            xx[mp[arr[i]].first]++;
            yy[mp[arr[i]].second]++;
            if(xx[mp[arr[i]].first]==m || yy[mp[arr[i]].second]==n)
            return i;
        }
        return arr.size();
    }
};