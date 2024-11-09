class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>arr;
        int n=nums.size();
        int curr=0;
        for(int i:nums)
        curr^=i;
        for(int i=0;i<n;i++)
        {
            int ans=0;
            for(int j=0;j<maximumBit;j++){
            if(curr&(1<<j))
            continue;
            ans|=(1<<j);
            }
            arr.push_back(ans);
            curr^=nums[n-1-i];
        }
        return arr;
    }
};