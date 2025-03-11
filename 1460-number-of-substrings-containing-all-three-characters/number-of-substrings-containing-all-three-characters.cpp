class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>arr(3);
        int curr=0;
        int i=0;
        int ans=0;
        int j=0;
        while(j<n)
        {
            arr[s[j]-'a']++;
            curr|=(1<<(s[j]-'a'));;
            while(curr==7)
            {
                ans+=(n-j);
                arr[s[i]-'a']--;
                if(arr[s[i]-'a']==0)
                curr^=(1<<(s[i]-'a'));
                i++;
            }
            j++;
        }
        return ans;
    }
};