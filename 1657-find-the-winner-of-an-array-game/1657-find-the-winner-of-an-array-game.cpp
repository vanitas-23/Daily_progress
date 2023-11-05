class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k == 1) 
            return max(arr[0], arr[1]);
        if (k >= arr.size()) 
            return *max_element(arr.begin(), arr.end());
        
        vector<int>d(arr.begin(),arr.end());
        stack<int>st;
        int n=arr.size();
        int c=0;
        int mx=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(c==k)
            return st.top();
            if(c>mx)
                    ans=st.top(),mx=c;
            if(c==mx && mx!=0)
            ans=st.top(),mx=c;
            if(st.empty())
            st.push(d[i]);
            else {
                if(st.top()>d[i])
                c++;
                else{
                    
                    st.pop();
                    st.push(d[i]);
                    c=1;
                }
            }
        }
        if(c>mx)
                    ans=st.top(),mx=c;
            if(c==mx && mx!=0)
            ans=st.top(),mx=c;

        if(c!=k)
        return *max_element(arr.begin(), arr.end());
        return ans;
    }
};