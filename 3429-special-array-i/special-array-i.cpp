class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        bool isO=(nums[0]%2);
        for(int i=1;i<n;i++)
        {
            bool x = nums[i]%2;
            if(x==isO) return 0;
            isO=x;
        }
        return 1;
    }
};