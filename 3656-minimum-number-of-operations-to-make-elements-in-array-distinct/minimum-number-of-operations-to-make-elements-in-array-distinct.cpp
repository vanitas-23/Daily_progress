class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>arr(101);
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(arr[nums[i]])
            return ceil((i+1)*1.0/3);
            else
            arr[nums[i]]=1;
        }
        return 0;
    }
};