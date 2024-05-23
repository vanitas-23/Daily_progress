class Solution {
public:
    int f(int i,int n,vector<int>& nums,vector<int>& temp,int k)
    {
        if(i==n)
        return temp.size()>0;
        int nt=f(i+1,n,nums,temp,k);
        int t=0;
        
        
            for(int it:temp)
            if(abs(it-nums[i])==k)
            return nt;
            temp.push_back(nums[i]);
            t=f(i+1,n,nums,temp,k);
            temp.pop_back();
        
        return t+nt;
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp;
        return f(0,n,nums,temp,k);
    }
};