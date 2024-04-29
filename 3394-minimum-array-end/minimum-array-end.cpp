class Solution {
public:
    long long minEnd(long long n, long long x) {
        vector<int>arr;
        for(int i=0;i<64;i++)
        {
            if(x&(1LL<<i))
            continue;
            arr.push_back(i);
        }
        int ans=n-1;
        int j=0;
        for(int i=0;i<64;i++)
        {
            if(ans&(1LL<<i))
            x|=(1LL<<arr[j]);
            j++;
        }
        return x;
    }
};