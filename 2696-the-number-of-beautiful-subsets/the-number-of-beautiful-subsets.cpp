class Solution {
public:
    int f(int i,int n,vector<int>& nums,vector<int>& temp,int k)
    {
        if(i==n)
        {
            for(int j=0;j<temp.size();j++)
            {
                auto it=lower_bound(temp.begin(),temp.end(),temp[j]+k);
                if(it!=temp.end() && *it==temp[j]+k)
                return 0;
            }
            return 1;
        }
        int nt=f(i+1,n,nums,temp,k);
        temp.push_back(nums[i]);
        int t=f(i+1,n,nums,temp,k);
        temp.pop_back();
        return nt+t;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        return f(0,nums.size(),nums,temp,k)-1;
    }
};