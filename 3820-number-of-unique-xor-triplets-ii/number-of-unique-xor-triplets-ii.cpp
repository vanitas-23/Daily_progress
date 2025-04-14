class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s.insert(nums[i]^nums[j]);
            }
        }
        vector<int> vis(2049,0);
        for(int i=0;i<n;i++){
            for(auto &x:s){
                vis[nums[i]^x] =1;
            }
        }
        int ct=0;
        for(int i=0;i<=2048;i++){
            if(vis[i]==1) ct++;
        }
        return ct;
        
    }
};