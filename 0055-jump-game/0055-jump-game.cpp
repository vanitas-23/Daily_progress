class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        if(nums[0]==0 && n==1)
        return true;
         if(nums[0]==0)
        return false;
       int mx=nums[0];
       for(int i=1;i<n;i++){
           mx--;
           mx=max(mx,nums[i]);
        
           if(mx==0 && i!=n-1)
           return false;
       }
       return true;
    }
};