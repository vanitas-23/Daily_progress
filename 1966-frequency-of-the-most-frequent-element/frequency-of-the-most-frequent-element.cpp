class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long curr=0;
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            curr+=nums[j];
    
            while((j-i+1)*1LL*nums[j]-curr > k)
            curr-=nums[i],i++;

            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};