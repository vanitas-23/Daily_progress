class Solution {
public:
    bool f(string& s,int k)
    {
        unordered_map<int,int>mp;
        vector<int>arr(26);
        int mask=0;
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
            mask|=(1<<(s[i]-'a'));
            if(i<k-1)
            continue;
            
            if(__builtin_popcount(mask)==1)
            mp[mask]++;
            arr[s[i-k+1]-'a']--;
            if(arr[s[i-k+1]-'a']==0)
            mask^=(1<<(s[i-k+1]-'a'));
        }
        
        for(auto i:mp)
        if(i.second>=3)
        return 1;
        return 0;
    }
    int maximumLength(string s) {
        
        int n=s.size();
        int l=1;
        int r=n;
        int ans=0;
        while(l<=r)
        {
            
            int mid=(l+r)/2;
            cout<<mid<<" ";
            if(f(s,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return ans==0?-1:ans;
    }
};