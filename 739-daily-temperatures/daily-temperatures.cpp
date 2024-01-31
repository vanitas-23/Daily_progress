class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>arr(n);
        stack<pair<int,int>>st;
        st.push({t[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && t[i]>=st.top().first)
            st.pop();
            if(!st.empty())
            arr[i]=st.top().second-i;
            st.push({t[i],i});
        }
        return arr;
    }
};