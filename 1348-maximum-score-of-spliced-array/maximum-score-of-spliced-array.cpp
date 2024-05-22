class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>rec(n);
        for(int i=0;i<n;i++)
        rec[i]=nums1[i]-nums2[i];
        int mx=0;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=rec[i];
            mx=max(mx,temp);
            if(temp<0)
            temp=0;
        }
        int res=accumulate(nums2.begin(),nums2.end(),0)+mx;
        for(int i=0;i<n;i++)
        rec[i]=nums2[i]-nums1[i];
         mx=0;
         temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=rec[i];
            mx=max(mx,temp);
            if(temp<0)
            temp=0;
        }
        res=max(res,accumulate(nums1.begin(),nums1.end(),0)+mx);
        return res;
    }
};