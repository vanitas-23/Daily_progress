class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr2.size();

        map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[arr2[i]]=i;

        auto cmp=[&mp](int a,int b){
            if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end())
            return mp[a]<mp[b];
            if(mp.find(a)!=mp.end())
            return true;
            if(mp.find(b)!=mp.end())
            return false;
            return a<b;
        };
        sort(arr1.begin(),arr1.end(),cmp);
        return arr1;
    }
};