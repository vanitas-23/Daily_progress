class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>arr(26);
        for(char c:word)
            arr[c-'a']++;
        sort(arr.begin(),arr.end());
        vector<int>p=arr;
     
        for(int i=24;i>=0;i--)
            p[i]+=p[i+1];
        long long ans=word.size();
        int temp=0;
        int n=arr.size();
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)
                continue;
            auto it=upper_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin();
            it--;
            long long sm=p[it]-arr[it];
            long long req = (n-it-1)*1LL*(arr[i]+k);
            ans=min(ans,temp+sm-req);
            temp+=arr[i];
       
        }
        return ans;
    }
};