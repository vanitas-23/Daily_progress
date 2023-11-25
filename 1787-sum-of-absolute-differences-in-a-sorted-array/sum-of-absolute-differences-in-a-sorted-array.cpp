class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int acc=accumulate(nums.begin(),nums.end(),0);
        int l=0;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int r=acc-l-nums[i];
            res[i]=i*nums[i]-l+r-(n-i-1)*nums[i];
            l+=nums[i];
        }
        return res;
    }
};