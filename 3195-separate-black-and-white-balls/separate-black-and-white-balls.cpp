class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int curr=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                ans+=(i-curr),curr++;
        }
        return ans;
    }
};