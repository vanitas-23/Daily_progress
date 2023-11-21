class Solution {
public:
    int countNicePairs(vector<int>& nums) {
       
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int num:nums) {
            int dup = num;
            int rev = 0;
            while(dup>0) {
                rev = rev*10 + dup%10;
                dup = dup/10;
            }
            ans+= mp[(num-rev)];
            ans = ans%1000000007;
            mp[(num-rev)]++;
        }
        return ans;
    }
};