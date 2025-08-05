class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp.size()>2)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                mp.erase(nums[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};