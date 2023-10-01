class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for(int j:nums){
            if(j!=0){
            nums[i]=j;
            i++;}
        }
        while(i<n){
        nums[i]=0;
        i++;}
    }
};