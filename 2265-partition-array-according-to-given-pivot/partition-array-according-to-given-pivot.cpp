class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n=nums.size();
        int l=0;
        vector<int>res(n);
        for(auto i:nums)
        {
            if(i<p)
            res[l++]=i;
        }
        for(auto i:nums)
        {
            if(i==p)
            res[l++]=p;
        }
        for(auto i:nums)
        {
            if(i>p)
            res[l++]=i;
        }
        return res;
    }
};