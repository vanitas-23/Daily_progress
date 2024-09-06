class Solution {
public:
    bool isPos(int moves, vector<int> &nums, vector<int> &changeIndices)
    {
       int n = nums.size();
       int m = changeIndices.size();
        
         // all 1 based indexing 
        vector<int> lastOccurence(n+1, -1);
        for(int i = moves-1; i>=0; i--)
        {
            int ind = changeIndices[i];
            if(lastOccurence[ind] == -1)
            {
                lastOccurence[ind] = i+1;
            }
        }
        
        for(int i = 1; i<=n; i++)
        {
            if(lastOccurence[i] == -1)
                return false;
        }
        
        vector<pair<int,int>> vpr;
        for(int i = 1; i<=n; i++)
        {
            vpr.push_back({lastOccurence[i], i});
        }
        
        sort(vpr.begin(), vpr.end());
        
        
        long long cnt = 0;  
        for(int i = 0; i< vpr.size(); i++)
        {
            int lastInd = vpr[i].first;
            int ind = vpr[i].second;
            int needed = nums[ind-1];
            
            int available = lastInd - 1- cnt;
            if(available >= needed)
            {
                cnt += needed + 1;
            }
            else
                return false;
        }
        
        return true;
        
        
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        long long  minNeeded = 0;
        for(int i = 0; i< n ; i++)
        {
            minNeeded += nums[i] + 1;
        }
        
        if(minNeeded > m)
            return -1;
        
        int lo = minNeeded;
        int hi = m;
        // FFFFFTTTTTT, minimum true 
        while(hi - lo > 1)
        {
            int mid = (hi + lo)/2;
            if(isPos(mid, nums, changeIndices))
                hi = mid;
            else
                lo = mid + 1;
        }
        if(isPos(lo, nums, changeIndices))
            return lo;
        if(isPos(hi, nums, changeIndices))
            return hi;
        
        return -1;
        
        
    }
};