class Solution {
public:
    int minimumLength(string s) {
        vector<int>arr(26);
        for(char c:s)
        arr[c-'a']++;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0) continue;
            if(arr[i]%2)
            ans++;
            else
            ans+=2;
        }
        return ans;
    }
};