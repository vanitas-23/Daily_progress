class Solution {
public:
    map<string,int>mp;
    vector<string> res;
    void f(int i,int n,string& s,vector<string>& curr)
    {
        if(i==n)
        {
            string r="";
            int cnt=0;
            for(auto i:curr){
            r+=i;
            r+=" ";
            cnt+=i.size();
            }
            r.pop_back();
            if(cnt==n)
            res.push_back(r);
        }
        for(int j=i+1;j<=n;j++)
        {
            auto x=s.substr(i,j-i);
            if(mp.find(x)==mp.end())
            continue;
           // cout<<x<<" ";
            curr.push_back(x);
            f(j,n,s,curr);
            curr.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict)
        mp[i]++;
        int n = s.size();
        vector<string>curr;
        f(0,n,s,curr);
        return res;
    }
};