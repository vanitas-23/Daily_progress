class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int i:st)
        {
            if(st.find(i-1)!=st.end())
            continue;
            int x=i;
            int temp=0;
            while(st.find(x)!=st.end())
            temp++,x++;
            ans=max(ans,temp);
        }
        return ans;
    }
};