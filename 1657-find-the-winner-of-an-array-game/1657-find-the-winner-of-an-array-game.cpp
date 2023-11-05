class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
       
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
            st.push(arr[i]);
            else {
                if(st.top()>arr[i])
                c++;
                else{
                    
                    st.pop();
                    st.push(arr[i]);
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