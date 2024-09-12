class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int>arr;
        for(int i=0;i<64;i++){
        if(x&(1ll<<i))
        continue;
        arr.push_back(i);
        }
        n--;
        int j=0;
        long long ans=x;
        //cout<<ans<<" "<<n;
        for(int i=0;i<64;i++)
        {
            if((n*1ll)&(1ll<<i))
            ans|=(1ll<<arr[j]);
            j++;
        }
        return ans;
    }
};