class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int top=-1;
        int ans=0;
        int cnt=0;
        for(int i:nums){
            if(top==-1)
            top=i,cnt=1;
            else{
                    if(top!=i)
                    ans+=cnt;
                    cnt++;
                    top=i;
            }
            
        }
        return ans;

    }
};