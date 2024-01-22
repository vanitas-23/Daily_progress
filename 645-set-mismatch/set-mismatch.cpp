class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int ele=-1;
        for(int i:nums)
        if(nums[abs(i)-1]<0)
        ele=abs(i);
        else
        nums[abs(i)-1]*=-1;
        vector<int>res(2);
        for(int i=0;i<nums.size();i++)
        if(nums[i]>0)
        res[1]=i+1;

        res[0]=ele;
        return res;
    }
};