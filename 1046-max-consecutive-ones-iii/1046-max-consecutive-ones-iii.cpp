class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        for( int j=0;j<nums.size();j++){
                if(nums[j]==0)
                k--;
                if(k<0){
                    if(nums[i]==0)
                    k++;
                    i++;
                }
        }
        return n-i;
    }
};