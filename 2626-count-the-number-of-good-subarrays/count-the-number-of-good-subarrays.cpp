#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        ll temp=0;
        ll ans=0;
        map<int,int>mp;
        while(j<n)
        {
            temp+=mp[nums[j]];
            mp[nums[j]]++;
            while(temp>=k && i<=j)
            {
                ans+=(n-j);
                
                temp-=mp[nums[i]]-1;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};