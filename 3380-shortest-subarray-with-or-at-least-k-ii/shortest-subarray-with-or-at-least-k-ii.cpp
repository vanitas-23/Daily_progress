class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=n+1;
        vector<int>arr(32);
        int org=0;
        while(j<n)
        {
            org|=nums[j];
            for(int x=0;x<=31;x++)
                if(nums[j]&(1<<x))
                arr[x]++;

            while(org>=k && i<=j)
            {
                ans=min(ans,j-i+1);
                for(int x=0;x<=31;x++)
                if(nums[i]&(1<<x))
                arr[x]--;
                org=0;
                for(int x=0;x<=31;x++)
                if(arr[x]>0)
                org|=(1<<x);
                i++;
            }
            j++;
        }
        return ans==n+1?-1:ans;
    }
};