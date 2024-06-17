class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long mp[1024] = { 1 };
        int mask=0;
        long long ans=0;
        for(auto i:word)
        {
            mask^=(1<<(i-'a'));
            
            //mp[mask]=1;
            ans+=mp[mask];
            for(int j=0;j<10;j++)
            ans+=mp[mask^(1<<j)];
            mp[mask]++;
        }
        return ans;
    }
};