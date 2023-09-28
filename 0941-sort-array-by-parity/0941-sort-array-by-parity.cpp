class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            if(nums[l]%2>nums[r]%2){
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
            }

            if(nums[l]%2==0){
                l++;
            }
                
            if(nums[r]%2==1){
                r--;
            }
        }
        return nums;
        
    }
};