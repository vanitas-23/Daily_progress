class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>temp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        temp.push_back({nums[i],i});
        sort(temp.begin(),temp.end());
        vector<int>ans(n);
        int curr=-1;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(curr==-1)
            curr=temp[i].first,last=i;
            else
            {
                if(temp[i].first-curr>limit)
                {
                    vector<int>idc;
                    vector<int>ele;
                    for(int j=last;j<i;j++)
                    idc.push_back(temp[j].second),ele.push_back(temp[j].first);
                    sort(idc.begin(),idc.end());
                    sort(ele.begin(),ele.end());
                    for(int j=0;j<idc.size();j++)
                    ans[idc[j]]=ele[j];
                    last=i;
                }
                curr=temp[i].first;
            }
        }
        vector<int>idc;
                    vector<int>ele;
                    for(int j=last;j<n;j++)
                    idc.push_back(temp[j].second),ele.push_back(temp[j].first);
                    sort(idc.begin(),idc.end());
                    sort(ele.begin(),ele.end());
                    for(int j=0;j<idc.size();j++)
                    ans[idc[j]]=ele[j];
        return ans;
    }
};