class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, set<int>> mp;
        for(auto &it: nums) {
            mp[abs(it)].insert(it);
        }
        int maxi = -1;
        
        for(auto &it: mp) 
            if(it.second.size() == 2) 
                maxi = max(it.first, maxi);
            
        
        return maxi ;
    }
};