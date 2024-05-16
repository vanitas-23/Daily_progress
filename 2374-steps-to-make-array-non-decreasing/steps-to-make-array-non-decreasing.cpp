class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n=nums.size();
        int ans=0;
        st.push({nums[n-1],0});
       for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!st.empty() && st.top().first<nums[i]){
                
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            ans=max(cnt,ans);
            st.push({nums[i],cnt});
       } 

       return ans;
    }
};