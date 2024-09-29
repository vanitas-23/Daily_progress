class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>st(nums.begin(),nums.end());
        sort(st.begin(),st.end());
        vector<int>res;
        for(auto i:nums)
        {
            auto it=lower_bound(st.begin(),st.end(),i);
            res.push_back(it-st.begin());
        }
        return res;
    }
};