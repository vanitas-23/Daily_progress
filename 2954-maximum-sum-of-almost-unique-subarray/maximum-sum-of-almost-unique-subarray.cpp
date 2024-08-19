class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0, ans = 0;
        int i = 0, j = 0, n = nums.size();
        unordered_map<int,int> mp;
        for(i = 0; i < n; i++){
            if(i<k-1){
                mp[nums[i]]++;
                sum += nums[i];
            }else{
                sum += nums[i];
                mp[nums[i]]++;
                if(mp.size()>=m){
                    ans = max(ans,sum);
                }
                sum -= nums[i-k+1];
                mp[nums[i-k+1]]--;
                if(mp[nums[i-k+1]]==0){
                    mp.erase(nums[i-k+1]);
                }
            }
        }
        return ans;
    }
};