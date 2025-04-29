class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int i=0,j=0;
        int mx=*max_element(nums.begin(),nums.end());
        int cnt=0;
        while(j<n)
        {
            cnt+=(nums[j]==mx);
            while(cnt>=k)
            {
                ans+=(n-j);
                cnt-=(nums[i++]==mx);
            }
            j++;
        }
        return ans;
    }
};