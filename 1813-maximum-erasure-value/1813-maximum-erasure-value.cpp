class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int sum=0;
        int j=0;
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                sum+=nums[i];
                st.insert(nums[i]);
                ans=max(ans,sum);
            }
            else{
                while(st.find(nums[i])!=st.end()){
                    st.erase(nums[j]);
                    sum-=nums[j];
                    j++;
                }
                st.insert(nums[i]);
                sum+=nums[i];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};