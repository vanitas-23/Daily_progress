class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        int mx=*max_element(nums.begin(),nums.end());
        while(j<n)
        {
            if(nums[j]==mx)
            cnt++;
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