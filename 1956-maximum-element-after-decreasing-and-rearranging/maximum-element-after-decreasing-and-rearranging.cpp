class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
       
        sort(arr.begin(),arr.end());
        int ans=1;
        int n=arr.size();
        //if(arr[0]!=1)
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<2)
            ans=arr[i];
            else
            ans=arr[i-1]+1,arr[i]=arr[i-1]+1;
        }
        return ans;
    }

};