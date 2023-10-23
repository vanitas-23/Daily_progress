
static auto _enhancer = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==1)
        return 0;
        vector<int>v;
         int one=0,zer=0;
         for(int i=0;i<nums.size();i++){
             if(nums[i]==1){
             one++;
            zer=0;
             }
             else{
                if(one>0)
                 v.push_back(one);
                 one=0;
                 zer++;
                 if(zer>1)
                 v.push_back(0);
             }
         }
         if(one>0)
         v.push_back(one);
         if(v.back()==nums.size())
         return v.back()-1;
         int maxx=v[0];
         int res;
         
         for(int i=1;i<v.size();i++){
            maxx=max(v[i]+v[i-1],maxx);
         }
     return v.size()>0?maxx:1;   
    }
};