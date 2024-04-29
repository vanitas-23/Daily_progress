class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int curr=0;
        for(int i:nums)
        curr^=i;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(curr&(1<<i))
            {
                if(k&(1<<i))
                continue;
                ans++;
            }
            else
            {
                if(k&(1<<i))
                ans++;
            }
        }
        return ans;
    }
};