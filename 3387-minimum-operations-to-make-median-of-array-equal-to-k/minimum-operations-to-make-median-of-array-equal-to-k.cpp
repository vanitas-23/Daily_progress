class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[n/2]==k)
            return 0;
        int curr=n/2;
        long long op=0;
        while(curr>=0 && nums[curr]>k)
        {
            op+=1LL*abs(nums[curr]-k);
            curr--;
        }
        curr=n/2;
        while(curr<n && nums[curr]<k)
        {
            op+=1LL*abs(nums[curr]-k);
            curr++;
        }
        return op;
    }
};