class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        auto x=arr;
        int n=arr.size();
        for(int i=1;i<n;i++)
        arr[i]^=arr[i-1];
        vector<int>ans;
        for(auto i:q)
        {
            ans.push_back(arr[i[1]]);
            if(i[0]>0)
            ans.back()^=arr[i[0]-1];
        }
        return ans;
    }
};