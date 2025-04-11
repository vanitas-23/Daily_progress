class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.size();
        if(n==0)
        return ans;
        int i=0;
        int j=0;
        map<char,int>arr;
        while(j<n)
        {
            arr[s[j]]++;
            while(arr[s[j]]>1)
            arr[s[i++]]--;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};