class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre=nums;
        vector<int>post=nums;
        for(int i=1;i<n;i++)
            pre[i]*=pre[i-1];
        for(int i=n-2;i>=0;i--)
            post[i]*=post[i+1];
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                res[i]=post[i+1];
            else if(i==n-1)
                res[i]=pre[i-1];
            else
                res[i]=pre[i-1]*post[i+1];
            
        }
        return res;
    }
};