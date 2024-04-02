class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=r-(r-l)/2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && 
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
        if(mid > 0 && arr[mid - 1] > arr[mid])
            r=mid-1;
        else
            l=mid+1;
        }
        return -1;
    }
};