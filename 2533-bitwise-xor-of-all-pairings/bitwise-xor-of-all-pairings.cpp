class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n=nums1.size();
        int m=nums2.size();
        if(m%2)
        for(int i:nums1)
        ans^=i;
        if(n%2)
        for(int i:nums2)
        ans^=i;
        return ans;
    }
};