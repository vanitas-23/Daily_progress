class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>res;
        vector<int>temp;
        for(int i:nums)
        {
            temp.push_back(i);
            if(temp.size()==3)
            res.push_back(temp),temp={};
        }
        if(temp.size())
        res.push_back(temp);
        for(auto i:res)
        if(i.back()-(*i.begin())>k)
        return {};
        return res;
    }
};