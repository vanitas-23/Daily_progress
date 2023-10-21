class Solution {
public:
    bool can(vector<int>& nums, int threshold,int k){
        int ans=0;
        for(int i:nums)
        ans+=ceil(i*1.0/k);

        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=h;
        while(l<=h){
            int mid=h-(h-l)/2;
            if(can(nums,threshold,mid))
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