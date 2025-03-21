class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supp) {
        queue<string> q;
        unordered_map<string, vector<string>> mp;
        unordered_map<string,int>inD;
        unordered_set<string>st;
        vector<string>res;
        int n=rec.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ing[i].size();j++)
            {
                mp[ing[i][j]].push_back(rec[i]);
                inD[rec[i]]++;
            }
            st.insert(rec[i]);
        }
        for(auto i:supp)
        q.push(i);
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            if(st.find(x)!=st.end())
            {
                res.push_back(x);
                st.erase(x);
            }
            for(auto i:mp[x])
            {
                inD[i]--;
                if(inD[i]==0)
                q.push(i);
            }
        }
        return res;
    }
};