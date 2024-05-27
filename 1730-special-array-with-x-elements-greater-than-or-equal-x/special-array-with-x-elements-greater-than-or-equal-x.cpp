class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=1000;
        int n=nums.size();
        while(l<=r)
        {
            int md=(l+r)/2;
            auto it=lower_bound(nums.begin(),nums.end(),md)-nums.begin();
            if(n-it==md)
            return md;
            if(n-it>md)
            l=md+1;
            else
            r=md-1;
        }
        return -1;
    }
};