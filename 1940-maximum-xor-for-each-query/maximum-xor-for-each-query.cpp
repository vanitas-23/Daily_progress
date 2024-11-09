class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>arr;
        int n=nums.size();
        int curr=0;
        int mask=(1<<maximumBit)-1;
        for(int i:nums)
        curr^=i;
        for(int i=0;i<n;i++)
        {
            arr.push_back(curr^mask);
            curr^=nums[n-1-i];
        }
        return arr;
    }
};