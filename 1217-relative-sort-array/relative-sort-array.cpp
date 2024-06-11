class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m=arr2.size();
        sort(arr1.begin(),arr1.end());
        map<int,int>mp;
        for(int i=0;i<m;i++)
            mp[arr2[i]]=i+1;
        auto cmp = [&mp](int a,int b){
            return mp[a]<mp[b];
        };

        
      

vector<int> org,temp;
        for(int i:arr1){
            if(mp.find(i)==mp.end())
                temp.push_back(i);
            else
                org.push_back(i);
        }


       sort(org.begin(), org.end(), cmp);

sort(temp.begin(),temp.end());
        org.insert(org.end(),temp.begin(),temp.end());


        return org;
    }
};