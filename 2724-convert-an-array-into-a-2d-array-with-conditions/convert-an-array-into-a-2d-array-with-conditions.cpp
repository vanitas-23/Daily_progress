class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(mp.size()>0){
            vector<int> v;
            vector<int> f;
            for(auto it=mp.begin();it!=mp.end();it++){
                cout<<mp.size();
                v.push_back(it->first);
                int x=it->second;
                mp[it->first]=x-1;
                if(x-1==0){
                   f.push_back(it->first);
                }
            }
            for(int i=0;i<f.size();i++){
                mp.erase(f[i]);
            }
            ans.push_back(v);
          //  cout<<mp.size()<<" ";
        }
        return ans;
    }
};