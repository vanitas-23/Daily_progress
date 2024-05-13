class Solution {
public:
    int largestCombination(vector<int>& can) {
        vector<int>arr(31);
        for(int i:can)
        {
            for(int j=0;j<31;j++)
            if(i&(1<<j))
            arr[j]++;
        }
        return *max_element(arr.begin(),arr.end());
    }
};