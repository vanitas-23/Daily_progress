class Solution {
public:
    int f(vector<string>& arr,int i,int n,string s)
    {
        if(i==n)
        return s.size();
        int ntaken=f(arr,i+1,n,s);
        int taken=0;
        unordered_set<char>st(s.begin(),s.end());
        for(char c:arr[i])
        if(st.find(c)!=st.end())
        return ntaken;
        else
        st.insert(c);
        s+=arr[i];
        taken=f(arr,i+1,n,s);
        return max(taken,ntaken);
    }
    int maxLength(vector<string>& arr) {
        string s="";
        return f(arr,0,arr.size(),s);
    }
};