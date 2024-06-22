class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        for(int i=0;i<32;i++)
        {
            if(st.find(1<<i)==st.end())
            return (1<<i);
        }
        return 0;
    }
};