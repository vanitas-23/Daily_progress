class Solution {
public:
    int uniqueLetterString(string s) {
        int ans=0;
        vector<int>adj[26];
        for(int i=0;i<26 ;i++)  adj[i].push_back(-1);
        for(int i=0;i<s.size();i++) adj[s[i]-'A'].push_back(i);
        for(int i=0;i<26;i++) adj[i].push_back(s.size());

        for(int i=0;i<26;i++)
        {
            int n=adj[i].size();
            for(int j=1;j<n-1;j++)
            ans+=(adj[i][j]-adj[i][j-1]) * (adj[i][j+1]-adj[i][j]);
        }
        return ans;
    }
};