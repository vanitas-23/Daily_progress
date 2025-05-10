class Solution {
public:
    bool can(int vac1,int vac2,long long mid,long long sum1,long long sum2){
        long long req1=mid-sum1;
        long long req2=mid-sum2;
        
        bool c1=vac1==0?req1==0:(req1>=vac1);
        bool c2=vac2==0?req2==0:(req2>=vac2);
        return c1&c2;
    }
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=accumulate(nums1.begin(),nums1.end(),0ll);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0ll);
        int vac1=0;
        int vac2=0;
        for(int i:nums1)
            if(i==0)
                vac1++;
        for(int i:nums2)
            if(i==0)
                vac2++;
        
        long long low=1;
        long long high=1e12;
        if(vac1==0)
        high=sum1;
        else if(vac2==0)
        high=sum2;
        long long ans=-1;
        while(low<=high){
            long long mid=high-(high-low)/2;
           
            if(can(vac1,vac2,mid,sum1,sum2)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
                
        }
        
        return ans;
    }
};