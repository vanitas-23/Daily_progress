class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                
                int tar=nums[i]+nums[l]+nums[r];
                if(tar==0)
                st.insert({nums[i],nums[l],nums[r]});
                if(tar<0)
                l++;
                else
                r--;
            }
        }
         vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};