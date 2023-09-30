class Solution {
public:
unordered_map<string,vector<pair<string,double>>>mp;
   void dfs(string start,string& end,unordered_set<string>& st,double val,double& ans){
       
        if(start==end)
        {
            ans=val;
            return ;
        }
        st.insert(start);
        
        for(auto it:mp[start]){
               if(st.find(it.first)==st.end()){
                    double val1=val;
                    val=val*it.second;
                    dfs(it.first,end,st,val,ans);
                    val=val1;
               }
        }

   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& value, vector<vector<string>>& queries) {
        
        int n=equations.size();
        for(int i=0;i<n;i++){
            mp[equations[i][0]].push_back({equations[i][1],value[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/(1.0*value[i])});
        }
        vector<double>res;
        n=queries.size();
        for(int i=0;i<n;i++){
            if(mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end())
            res.push_back(-1);
            else{
                
                unordered_set<string>st;
                double val=1.0;
                double ans=-1;
                dfs(queries[i][0],queries[i][1],st,val,ans);
                res.push_back(ans);
            }
        }
        return res;
    }
};