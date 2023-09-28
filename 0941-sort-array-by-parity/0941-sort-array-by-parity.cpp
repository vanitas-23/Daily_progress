class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int j=n-1;
        vector<int>res(n);
        for(int i:nums){
            if(i%2)
            {
                res[j]=i;j--;
            }
            else{
                res[l]=i;l++;
            }
        }
        return res;
    }
};