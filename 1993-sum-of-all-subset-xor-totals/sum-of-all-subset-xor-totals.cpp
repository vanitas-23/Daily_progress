class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i:nums)
        ans|=i;
        return ans*(1<<(n-1));
    }
};