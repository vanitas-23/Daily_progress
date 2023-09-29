class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=-1;
        int l=0;
        int r=nums[n-1];
        while(l<=r){
            int ctr=0;
            int mid = l+(r-l)/2;
        
            for(int i=0; i<nums.size(); i++)
                if(nums[i]>=mid)
                    ctr++;
                
            if(ctr==mid)
                return mid;
            
            if(ctr<mid)
                r = mid-1;
            
            else
                l = mid+1;      

        }
        return -1;
    }
};