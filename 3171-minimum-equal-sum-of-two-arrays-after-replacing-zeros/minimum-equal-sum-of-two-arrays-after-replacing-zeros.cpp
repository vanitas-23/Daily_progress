class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0LL);
        long long vac1=0;
        long long vac2=0;
        for(int i:nums1)
            if(i==0)
                vac1++;
        for(int i:nums2)
            if(i==0)
                vac2++;
        if(sum1+vac1 < sum2+vac2){
            swap(sum1,sum2);
            swap(vac1,vac2);
        }
        return ((sum1+vac1 > sum2) && (vac2==0))?-1:(sum1+vac1);
    }
};