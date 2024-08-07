#pragma GCC optimize("O3")
class Solution {
public:
    const int mod=1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) 
    {
        int n=nums.size();
        vector<long long> A(n, 0L);
        #pragma unroll
        for(int i=0; i<n; i++){
            A[i]=(s[i]=='R')?(long long)nums[i]+d:(long long)nums[i]-d;
        }
        sort(A.begin(), A.end());
        long long distance=0;
        
        for(int i=0; i<n; i++)
           distance=(distance+(-n+1+(2L*i))*A[i])%mod;
        return distance<0?distance+mod:distance;
    }
};