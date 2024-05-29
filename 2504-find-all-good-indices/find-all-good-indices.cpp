class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        vector<int> inc(nums.size(),0), dec(nums.size(),0) ; 
        vector<int> res; 
        int n = 1;
        for(int i=1;i<nums.size();i++){
            if(n>=k) inc[i]=1;
            if(nums[i]<=nums[i-1]) n++;
            else n=1;
        }
        n=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(n>=k) dec[i]=1;
            if(nums[i]<=nums[i+1]) n++;
            else  n=1;
        }
        for(int i=k;i<nums.size()-k;i++)
            if(inc[i]==1 && dec[i]==1)res.push_back(i);
        return res;
    }
};