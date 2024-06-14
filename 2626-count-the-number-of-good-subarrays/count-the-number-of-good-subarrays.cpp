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
                ll prev=mp[nums[i]];
                ll curr=prev-1;
                mp[nums[i]]--;
                ll diff=prev*(prev-1)/2-curr*(curr-1)/2;
                temp-=diff;
                i++;
            }
            j++;
        }
        return ans;
    }
};