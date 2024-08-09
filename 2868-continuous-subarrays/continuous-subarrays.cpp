class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        multiset<int>st;
        int n=nums.size();
        int i=0;
        int j=0;
        map<int,int>mp;
        while(j<n)
        {
            st.insert(nums[j]);
            bool b=0;
            
            while(*st.rbegin()-*st.begin()>2)
            {
                b=1;
                st.erase(st.lower_bound(nums[i++]));
            }
            mp[i]=max(mp[i],j);
            j++;
        }
        int curr=-1;
        for(auto i:mp)
        {
            int x = i.second-i.first+1;
            ans+=(x*1ll*(x+1))/2;
            if(curr>=i.first)
            {
                int y=curr-i.first+1;
                ans-=(y*1ll*(y+1))/2;
            }
            curr=i.second;
        }
        return ans;
    }
};