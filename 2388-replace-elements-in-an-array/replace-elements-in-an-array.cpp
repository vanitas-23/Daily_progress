class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int n = nums.size();
        for(int i=0;i<n;i++)
        mp1[i]=nums[i],mp2[nums[i]]=i;
        for(auto i:op)
        {
            int id=mp2[i[0]];
            mp2.erase(i[0]);
            nums[id]=i[1];
            mp2[i[1]]=id;
        }
        return nums;
    }
};