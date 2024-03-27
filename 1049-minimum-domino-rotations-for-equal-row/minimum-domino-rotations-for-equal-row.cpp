class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mp1,mp2;
        int n=tops.size();
        
        for(int i=0;i<n;i++)
        {
            mp1[tops[i]]++;
            if(tops[i]!=bottoms[i])
            mp2[bottoms[i]]++;
        }
        int ans=n+1;
        for(int i=0;i<n;i++)
        {
            if(mp1[tops[i]]+mp2[tops[i]]>=n)
            ans=min(ans,min(mp1[tops[i]],mp2[tops[i]]));
        }
        mp1.clear();
        mp2.clear();
        swap(tops,bottoms);
        for(int i=0;i<n;i++)
        {
            mp1[tops[i]]++;
            if(tops[i]!=bottoms[i])
            mp2[bottoms[i]]++;
        }
       // int ans=n+1;
        for(int i=0;i<n;i++)
        {
            if(mp1[tops[i]]+mp2[tops[i]]>=n)
            ans=min(ans,min(mp1[tops[i]],mp2[tops[i]]));
        }
        return ans==n+1?-1:ans;
    }
};