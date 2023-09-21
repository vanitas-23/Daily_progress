// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans=0;
        int l=0;
        int r=n;
        while(l<=r){
            int mid=r-(r-l)/2;
            
            if(isBadVersion(mid)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};