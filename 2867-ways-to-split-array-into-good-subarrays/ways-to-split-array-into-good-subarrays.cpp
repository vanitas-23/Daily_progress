class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int>can;
        int n=nums.size();
        int curr=0;
        int m=1e9+7;
        //nums.push_back(1);
        bool b=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                if(b)
                can.push_back(curr);
                b=1;
                curr=0;
            }
            else
            {
                curr++;
            }
        }
        if(!b)
        return 0;
        long long ans=1;
        for(int i:can)
        {
            ans = (ans%m * (i+1)%m)%m;
        }
        return ans;
    }
};