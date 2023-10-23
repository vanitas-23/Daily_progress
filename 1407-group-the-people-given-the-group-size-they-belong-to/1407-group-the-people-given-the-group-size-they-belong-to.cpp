class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>>res;
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
            if(mp[arr[i]].size()==arr[i]){
                  res.push_back(mp[arr[i]]);
                  mp.erase(arr[i]);
            }  
        }
        return res;

      
    }
};