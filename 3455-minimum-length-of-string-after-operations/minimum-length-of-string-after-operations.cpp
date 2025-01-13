class Solution {
public:
    int minimumLength(string s) {
        vector<int>arr(26);
        for(char c:s)
        arr[c-'a']++;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            while(arr[i]>2)
            arr[i]-=2;
            ans+=arr[i];
        }
        return ans;
    }
};