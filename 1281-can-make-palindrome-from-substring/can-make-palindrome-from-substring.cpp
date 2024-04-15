class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>pre(n);
        vector<bool>ans;
        pre[0]=1<<(s[0]-'a');
        for(int i=1;i<n;i++)
        pre[i]=pre[i-1]^(1<<(s[i]-'a'));
        for(auto x:queries)
        {
            int fst=x[0]==0?0:pre[x[0]-1];
            int snd=pre[x[1]];
            int ele=fst^snd;
            int cnt=__builtin_popcount(ele);
            if(cnt/2<=x[2])
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};