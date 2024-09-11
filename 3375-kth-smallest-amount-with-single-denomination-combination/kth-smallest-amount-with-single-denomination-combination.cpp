class Solution {
public:
    bool avail(long long mid,vector<int>& coins, int k)
    {
        long long ans=0;
            for(int i=1; i<(1<<coins.size()); i++){
                long long lcm=0, cnt=0;
                for(int j=0; j<coins.size(); j++){
                    if(i&(1<<j)){
                        cnt++;
                        if(lcm==0)lcm=coins[j];
                        else lcm=lcm*coins[j]/__gcd(lcm, (long long)coins[j]);
                    }
                }
                if(cnt%2)ans+=mid/lcm;
                else ans-=mid/lcm;
            }
            return ans>=k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        long long l=0;
        long long h = 50*1e9+1;
        auto ans=h;
        while(l<=h)
        {
            long long mid=(l+h)/2;
            if(avail(mid,coins,k))
            {
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};