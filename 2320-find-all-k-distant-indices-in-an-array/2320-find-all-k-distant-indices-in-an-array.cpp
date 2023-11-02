class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool b=0;
            for(int j=i;j>=0;j--){
                if(b)
                break;
                if(abs(i-j)<=k && nums[j]==key)
                b=1;
            }
            for(int j=i+1;j<n;j++){
                if(b)
                break;
            if(abs(i-j)<=k && nums[j]==key)
            b=1;
        }
            if(b)
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};