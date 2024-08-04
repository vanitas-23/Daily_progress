class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>arr;
        int m=1e9+7;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=left-1;i<right && i<arr.size();i++)
        {
            ans=(ans%m+arr[i]%m)%m;
        }
        return ans;
    }
};