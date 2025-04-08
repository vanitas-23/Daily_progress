class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>arr(101);
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(arr[nums[i]])
            {
                if((i+1)%3==0)
                return (i+1)/3;
                return (i+1)/3+1;
            }
            else
            arr[nums[i]]=1;
        }
        return 0;
    }
};