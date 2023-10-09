class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        vector<int>v(2);
        auto it=lower_bound(nums.begin(),nums.end(),target);
        auto it1=upper_bound(nums.begin(),nums.end(),target);
        it1--;
        if(it>it1)
            return {-1,-1};
        v[0]=it-nums.begin();
        v[1]=it1-nums.begin();
        return v;
    }
};