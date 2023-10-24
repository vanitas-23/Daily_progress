class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long s=accumulate(nums.begin(),nums.end(),0);
        if(target>s)
        return 0;
        if(target==s)
        return nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int mn=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                mn=min(j-i+1,mn);
                i++;
            }
            j++;
        }
        if(mn==INT_MAX){
            return 0;
        }
        return mn;
    }
};