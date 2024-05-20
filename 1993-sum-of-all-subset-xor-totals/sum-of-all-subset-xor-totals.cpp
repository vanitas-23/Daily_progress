class Solution {
public:
    int f(int i,int n,vector<int>& nums,int curr)
    {
        if(i==n)
        return curr;
        int nt=f(i+1,n,nums,curr);
        int t =f(i+1,n,nums,curr^nums[i]);
        return t+nt;
    }
    int subsetXORSum(vector<int>& nums) {
        
        int n=nums.size();
        return f(0,n,nums,0);
        
    }
};