class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long>arr(26);
        int m=1e9+7;
        for(char c:s)
        arr[c-'a']++;
        while(t--)
        {
            vector<long long>x(26);
            for(int i=1;i<26;i++)
            x[i]=arr[i-1];
            x[0]=(x[0]%m+arr[25]%m)%m;
            x[1]=(x[1]%m+arr[25]%m)%m;
            arr=x;
        }
        int ans=0;
        for(auto i:arr)
        ans=(ans%m+i%m)%m;
        return ans;
    }
};