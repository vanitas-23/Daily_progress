class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int tt=0;
        for(int i:nums)
            tt^=i;
        tt^=k;
        return __builtin_popcount(tt);
    }
};