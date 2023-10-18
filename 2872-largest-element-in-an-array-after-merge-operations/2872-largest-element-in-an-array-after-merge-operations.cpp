class Solution {
public:


    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long maxv = nums[n-1], curv = nums[n-1];
        
        for(auto i = n-2; i >= 0; --i){
            if(curv >= nums[i]) curv += nums[i];
            else curv = nums[i];
            maxv = max(maxv, curv);
        }

        return maxv;
    }
};