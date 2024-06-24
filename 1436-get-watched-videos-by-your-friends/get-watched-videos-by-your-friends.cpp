class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& f, int id, int lvl) {
        map<int,vector<string>>myV;
        map<int,vector<int>>myF;
        map<string,int>mp;
        int n=wv.size();
        for(int i=0;i<n;i++)
        {
            for(auto j:wv[i])
            myV[i].push_back(j),mp[j]++;

            for(auto j:f[i])
            myF[i].push_back(j);

        }
        queue<int>q;
        q.push(id);
        vector<int>vis(n);
        vis[id]=1;
        vector<string>res;
        int st=0;
        while(!q.empty() && st<=lvl)
        {
            int m=q.size();
            map<string,int>mp1;
            for(int i=0;i<m;i++)
            {
                auto x=q.front();
                q.pop();
                //cout<<x<<" "<<st<<endl;
                for(auto f:myF[x])
                if(!vis[f]){
                    q.push(f);
                    vis[f]=1;
                }
                
                for(auto i:myV[x])
                mp1[i]++;
            }
            auto cmp=[&mp1](string a,string b){
                if(mp1[a]==mp1[b])
                return a<b;
                return mp1[a]<mp1[b];
            };
            if(st==lvl)
            {
                for(auto i:mp1)
                res.push_back(i.first);
                sort(res.begin(),res.end(),cmp);
            }
            st++;
        }
        
        return res;
    }
};