class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>post(n);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
            pre[i]=min(pre[i-1],nums[i]);
        for(int i=n-2;i>=0 ;i--)
            post[i]=min(post[i+1],nums[i]);
        
        int ans=INT_MAX;
        
        for(int i=1;i<n-1;i++)
            if(nums[i]>pre[i-1] && nums[i]>post[i+1])
            ans=min(ans,pre[i-1]+nums[i]+post[i+1]);
        return ans==INT_MAX?-1:ans;
    }
};