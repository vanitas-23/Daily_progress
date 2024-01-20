class Solution {
public:
        int sumSubarrayMins(vector<int>& arr) {
        vector<int>dp(arr.size());
        dp[0]=arr[0];
        stack<int>st;
        st.push(0);
        long long ans=arr[0];
        int cv=1e9+7;
        for(int i=1;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                long long tt = ((i-st.top()-1)*arr[i])%cv;
                dp[i]+=tt;
                dp[i]+=dp[st.top()];
                dp[i]+=arr[i];
                ans+=dp[i];
                st.push(i);
            }
            else
            {
                long long y = (i*arr[i])%cv;
                dp[i]+=y;
                dp[i]+=arr[i];
                ans+=dp[i];
                st.push(i);
            }
        }
        return ans%cv;
    }
};