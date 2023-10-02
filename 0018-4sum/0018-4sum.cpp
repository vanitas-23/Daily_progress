class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>res;
        for(int i=0;i<n;i++){
           
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<n;j++){
                
            int l=j+1;
            int h=n-1;
            while(l<h){
                long long sum=nums[i]*1LL+nums[j]+nums[l]+nums[h];
                if(sum==target){
                res.insert({nums[i],nums[j],nums[l],nums[h]});l++;h--;
                }
                else if(sum<target)
                l++;
                else
                h--;
            }
            }
    }
            vector<vector<int>>req(res.begin(),res.end());
        return req;
    }
};