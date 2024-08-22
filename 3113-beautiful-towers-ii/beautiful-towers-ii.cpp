class Solution {
public:
    vector<long long> f(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prevSmall(n, -1), leftSum(n, 0);
        leftSum[0] = nums[0];
        stack<int> st;
        st.push(0);

        for(int i=1;i<n;i++) {
            while(!st.empty() and nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) prevSmall[i] = st.top();

            int prevSmallIdx = prevSmall[i];
            int temp = i - prevSmallIdx;
            leftSum[i] += (temp*1LL*nums[i]);
            if(prevSmall[i] != -1) leftSum[i] += leftSum[prevSmallIdx];

            st.push(i);
        }
        return leftSum;
    }
    long long maximumSumOfHeights(vector<int>& mxx) {
        long long ans=0;
        auto l=f(mxx);
        reverse(mxx.begin(),mxx.end());
        auto r=f(mxx);
        int n=mxx.size();
        // for(int i=0;i<n;i++)
        // cout<<l[i]<<" "<<r[n-1-i]<<endl;
        for(int i=0;i<n;i++)
        ans=max(ans,l[i]+r[n-1-i]-mxx[n-1-i]);
        return ans;
    }
};