class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans=INT_MIN;
        int temp=0;
        for(int i:nums){
            if(temp<0){
                temp=0;
            }
            temp+=i;
            ans=max(ans,temp);
        }
        return ans;
    }
};