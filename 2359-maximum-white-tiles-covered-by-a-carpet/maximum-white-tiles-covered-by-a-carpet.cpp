class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int car) {
        sort(tiles.begin(),tiles.end());
        vector<int>arr;
        for(auto i:tiles)
        arr.push_back(i[1]-i[0]+1);
        for(int i=1;i<arr.size();i++)
        arr[i]+=arr[i-1];
        vector<int>sta;
        for(auto i:tiles)
        sta.push_back(i[0]);
        int ans=0;
        for(int i=0;i<tiles.size();i++)
        {
            auto it=upper_bound(sta.begin(),sta.end(),tiles[i][0]+car-1);
            it--;
            int idx=it-sta.begin();
            int sum=0;
            if(i>0)
            sum-=arr[i-1];
            if(idx>0)
            sum+=arr[idx-1];
            sum+=min(tiles[idx][1],tiles[i][0]+car-1)-tiles[idx][0]+1;
            ans=max(ans,sum);
        }
        return ans;
    }
};