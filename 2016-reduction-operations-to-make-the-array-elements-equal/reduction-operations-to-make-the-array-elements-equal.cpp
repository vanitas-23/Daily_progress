class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int top=-1;
        int ans=0;
        int cnt=0;
        for(int i:nums){
            
                    if(top!=i)
                    ans+=cnt;
                    top=i;

            cnt++;
        }
        return ans;

    }
};