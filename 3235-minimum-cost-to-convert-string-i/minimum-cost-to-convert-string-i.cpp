#define ll long long
//#define inf 1e10
#define adj mat
class Solution {
public:
    ll inf=1e12;
    
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> mat(26, vector<long long>(26, inf));
       
        int n = original.size();

        for (int i = 0; i < 26; i++){

            mat[i][i] = 0;
                          }
        for (int i = 0; i<n; i++) {

            int start = original[i] - 'a';

            int end = changed[i] - 'a';
            //cout<<start<<" "<<end<<endl;
            mat[start][end] = min(mat[start][end], 1LL*cost[i]);
        }
        ll ans = 0LL;
         for (int k = 0; k < 26; k++)

            for (int i = 0; i < 26; i++)

                for (int j = 0; j < 26; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        
        for (int i = 0; i < source.size(); i++) {
            int start = source[i] - 'a';
            int end = target[i] - 'a';
            // if (mat[start][end] == inf)
            //     return -1;
            if (start == end)
                continue;
            ans += mat[start][end];
            if(ans>=inf)
            return -1;
        }
        return ans;
    }
};