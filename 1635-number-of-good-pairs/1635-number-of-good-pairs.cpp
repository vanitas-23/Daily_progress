class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i:nums){
            if(mp.find(i)!=mp.end()){
                ans+=mp[i];
            }
            mp[i]++;
        }
        return ans;
    }
};