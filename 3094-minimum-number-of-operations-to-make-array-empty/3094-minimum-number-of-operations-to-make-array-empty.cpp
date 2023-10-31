class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        int temp=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
            temp++;
            else{
                if(temp==1)
                return -1;           
                cnt+=(temp+2)/3;
                temp=1;
            }
        }
        if(temp==1)
        return -1;
        return cnt+(temp+2)/3;
    }
};