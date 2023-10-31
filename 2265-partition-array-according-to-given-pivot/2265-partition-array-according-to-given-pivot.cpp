class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l=0,g=0,e=0;
        for(auto it:nums)
            if(it<pivot)l++;
            else if(it==pivot)e++;
        
        vector<int>res(nums.size());
        g=l+e;
        e=l;
        l=0;
        for(auto it:nums){
            if(it<pivot){
                res[l]=it,l++;
            }else if(it==pivot)res[e]=it,e++;
            else res[g]=it,g++;
        }
        return res;
    }
};