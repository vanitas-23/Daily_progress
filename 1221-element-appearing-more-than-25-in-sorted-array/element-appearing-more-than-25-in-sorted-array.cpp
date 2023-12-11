class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int req=n/4;
        if(n==1)
        return arr[0];
        int temp=1;
        for(int i=1;i<n;i++){
        
        if(arr[i]==arr[i-1])
        temp++;
        else
        temp=1;
        if(temp>req)
        return arr[i];
        }
        return temp;
    }
};