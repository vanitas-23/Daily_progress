class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int>mp;
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(i>=k-1)
            {
                int gt=x;
                for(int j=-50;j<=50;j++)
                {
                    gt-=mp[j];
                    if(gt<=0)
                    {
                        if(j<0)
                        res.push_back(j);
                        else
                        res.push_back(0);
                        break;
                    }
                }
                mp[nums[i-k+1]]--;
            }
        }
        return res;
    }
};