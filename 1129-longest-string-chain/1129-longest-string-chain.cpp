class Solution {
public:
    unordered_map<string,vector<string>>mp;
    unordered_map<string,int>dp;
    int dfs(string i){
    
       int ans=1;
       if(mp[i].size()==0)
       return dp[i]=ans;
       if(dp.find(i)!=dp.end())
       return dp[i];
       int mx=0;
       for(auto it:mp[i])
       mx=max(dfs(it),mx);
       return dp[i]=ans+mx;
    }
    unordered_set<string> gen(string s) {
    unordered_set<string> result;

    for (int i = 0; i < s.length(); i++) {
        string newString = s.substr(0, i) + s.substr(i + 1);
        result.insert(newString);
    }

    return result;
}
    int longestStrChain(vector<string>& words) {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
        int mx=0;
        for(auto i:words){
            mx=max(mx,(int)i.size());
            
            auto x=gen(i);
            
            vector<string>res(x.begin(),x.end());
            mp[i]=res;
        }
        int ans=0;
        
        for(auto i:words){
            ans=max(dfs(i),ans);
        }
        return ans-1;
    }
};