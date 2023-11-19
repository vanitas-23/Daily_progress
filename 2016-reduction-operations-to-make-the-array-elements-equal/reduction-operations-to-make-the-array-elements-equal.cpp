class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=1;
        int ans=0;
        int l=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==l){
                c++;
            }
            else{
                ans+=c;
                c++;
                l=nums[i];
            }
        }
        return ans;
    }
};