class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        return true;
        int b=arr[0]>arr[1]?1:-1;

        for(int i=1;i<n;i++){
            if(b==-1){
                if(arr[i]<arr[i-1])
                b=1;
                else if(arr[i]>arr[i-1])
                b=0;
                else
                continue;
            }
            if(arr[i]==arr[i-1])
            continue;
            if(arr[i]>arr[i-1] && !b)
            continue;
            if(arr[i]<arr[i-1] && b)
            continue;
            return false;
        }
        return true;
    }
};