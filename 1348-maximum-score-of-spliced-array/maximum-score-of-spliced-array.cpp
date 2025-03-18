#define ll long long
class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2)
    {
        int n=nums1.size();
        vector<ll>prf1(n),prf2(n);
        prf1[0]=nums1[0];
        prf2[0]=nums2[0];
        for(int i=1;i<n;i++)
        prf1[i]=prf1[i-1]+nums1[i],
        prf2[i]=prf2[i-1]+nums2[i];
        ll gain=0;
        ll mn=prf2[0]-prf1[0];
        for(int i=1;i<n;i++)
        {
            gain=max(prf2[i]-prf1[i]-mn,gain);
            mn=min(mn,prf2[i]-prf1[i]);
        }
        return prf1[n-1]+gain;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(f(nums1,nums2),f(nums2,nums1));
    }
};