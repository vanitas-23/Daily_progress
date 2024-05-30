class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum=nums[0];
        int res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            int avg=ceil(sum*1.0/(i+1));
            if(avg>res)
            res=avg;
        }
        return res;
    }
};