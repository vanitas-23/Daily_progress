class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int curr=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2)
            curr++;
            else
            curr=0;
            if(curr==3)
            return 1;
        }
        return 0;
    }
};