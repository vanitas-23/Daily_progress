class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int steps=0;
        for(int i=0;i<n;i++){
           
            if(nums1[i]>nums1[n-1] && nums2[i]>nums1[n-1])
                return -1;
            if(nums2[i]>nums2[n-1] && nums1[i]>nums2[n-1])
                return -1;
            if(nums1[i]>nums1[n-1] && nums1[i]>nums2[n-1])

                return -1;
            if(nums2[i]>nums2[n-1] && nums2[i]>nums1[n-1])
                return -1;
             
            if(nums1[i]>nums1[n-1]){
                steps++;
            }
            
            if(nums2[i]>nums2[n-1])
                steps++;
            
        }
        swap(nums1[n-1],nums2[n-1]);
         int ans=steps; steps=1;
        for(int i=0;i<n;i++){
           
            if(nums1[i]>nums1[n-1]){
                steps++;
            }
            
            if(nums2[i]>nums2[n-1])
                steps++;
            
        }
        return min(ans,steps);
    }
};