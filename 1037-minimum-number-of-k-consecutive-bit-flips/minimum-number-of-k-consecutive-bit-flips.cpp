class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n);

        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i>=k && arr[i-k]==1)
            curr--;

            if((curr+nums[i])%2==0)
            {
                if(i+k>n)
                return -1;
                ans++;
                curr++;
                arr[i]=1;
            }
        }
        //cout<<curr;
        return ans;
    }
};