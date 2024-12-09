class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(int& i:nums)
        i=i%2;
        int i=0;
        int j=1;
        vector<pair<int,int>>arr;
        while(j<n)
        {
            if(nums[j]==nums[j-1])
            {
                arr.push_back({i,j-1});
                i=j;
            }
            j++;
        }
        arr.push_back({i,j-1});
        vector<bool>res;
        for(auto i:queries)
        {
            int l=0;
            int r=arr.size()-1;
            int x=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(arr[mid].second>=i[1])
                {
                    x=mid;
                    r=mid-1;
                }
                else
                l=mid+1;
            }
            if(x==-1)
            res.push_back(false);
            else{
                if(i[0]>=arr[x].first)
                res.push_back(true);
                else
                res.push_back(false);
            }
        }
        return res;
    }
};