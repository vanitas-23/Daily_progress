class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        int ans=0;
        vector<int>arr(c.begin(),c.end());
        for(int i=0;i<k-1;i++)
        arr.push_back(c[i]);
        int sz=1;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]!=arr[i-1])
            sz++;
            else
            {
                if(sz>=k)
                ans+=sz-k+1;
                sz=1;
            }
        }
        if(sz>=k)
        ans+=sz-k+1;
        return ans;
    }
};