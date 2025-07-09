class Solution {
public:
    int maxFreeTime(int etime, int k, vector<int>& st, vector<int>& et) {
        vector<int>ev;
        vector<pair<int,int>>arr;
        for(int i=0;i<st.size();i++)
            arr.push_back({st[i],et[i]});
        sort(arr.begin(),arr.end());
        if(arr[0].first!=0)
        ev.push_back(arr[0].first);
        for(int i=1;i<arr.size();i++){
            ev.push_back(arr[i].first-arr[i-1].second);}
        if(arr.back().second!=etime){
            ev.push_back(etime-arr.back().second);}
        
        int ans=0;
        int temp=0;
        int i=0;
        int j=0;
        k++;
        while(j<ev.size())
        {
            temp+=ev[j];
            while(j-i+1>k)
                temp-=ev[i++];
            ans=max(ans,temp);
            j++;
        }
        return ans;
    }
};