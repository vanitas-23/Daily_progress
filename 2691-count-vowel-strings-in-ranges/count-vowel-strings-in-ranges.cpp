class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        vector<int>arr;
        for(auto i:words)
        {
            if(i[0]=='a' || i[0]=='e' || i[0]=='i' || i[0]=='o' || i[0]=='u')
            if(i.back()=='a' || i.back()=='e' || i.back()=='i' || i.back()=='o' || i.back()=='u')
            {
                arr.push_back(1);
                continue;
            }
            arr.push_back(0);
        }
        int n=arr.size();
        for(int i=1;i<n;i++)
        arr[i]+=arr[i-1];
        vector<int>res;
        for(auto i:q)
        if(i[0]==0)
        res.push_back(arr[i[1]]);
        else
        res.push_back(arr[i[1]]-arr[i[0]-1]);
        return res;
    }
};