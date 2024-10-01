class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mp(k);
        int pr=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                arr[i]=arr[i]%k;
                arr[i]=(arr[i]+k)%k;
            }
            if(mp[(k-arr[i]%k)%k])
            {
                pr++;
                mp[(k-arr[i]%k)%k]--;
                continue;
            }
            mp[arr[i]%k]++;
        }
        return pr==n/2;
    }
};