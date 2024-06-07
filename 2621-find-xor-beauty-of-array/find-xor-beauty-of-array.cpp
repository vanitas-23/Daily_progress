class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        vector<int>arr(32);
        for(int i:nums)
        for(int j=31;j>=0;j--)
        if(i&(1<<j))
        arr[j]=!arr[j];

        int ans=0;
        for(int i=31;i>=0;i--)
        if(arr[i])
        ans|=(1<<i);
        return ans;
    }
};