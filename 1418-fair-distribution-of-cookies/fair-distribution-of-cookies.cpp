class Solution {
public:
    int f(int i,int k,int n,vector<int>& cookies,vector<int>& arr)
    {
        if(i==n)
        return *max_element(arr.begin(),arr.end());
        int mn=1e9;
        for(int id=0;id<k;id++)
        {
            arr[id]+=cookies[i];
            mn=min(mn,f(i+1,k,n,cookies,arr));
            arr[id]-=cookies[i];
        }
        return mn;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int>arr(k);
        return f(0,k,n,cookies,arr);
    }
};