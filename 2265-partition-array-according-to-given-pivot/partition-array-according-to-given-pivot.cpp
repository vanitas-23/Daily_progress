class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n=nums.size();
        vector<int>l,e,g;
        for(auto i:nums)
        {
            if(i<p)
            l.push_back(i);
            else if(i==p)
            e.push_back(i);
            else
            g.push_back(i);
        }
        vector<int>ans;
        for(auto i:l)
        ans.push_back(i);
        for(auto i:e)
        ans.push_back(i);
        for(auto i:g)
        ans.push_back(i);
        return ans;
    }
};