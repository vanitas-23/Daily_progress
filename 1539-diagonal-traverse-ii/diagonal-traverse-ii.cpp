class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>res;
        queue<pair<int,int>>q;
        int n=nums.size();
        q.push({0,0});
        //res.push_back(nums[0][0]);
        vector<vector<int>>kp=nums;
        for(auto& i:kp)
            fill(i.begin(),i.end(),0);
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
           // cout<<kp[i][j]<<" ";
            if(kp[i][j])
            continue;
            res.push_back(nums[i][j]);
            kp[i][j]=1;
            if(i+1<n && j<nums[i+1].size())
            q.push({i+1,j});
            if(j+1<nums[i].size())
            q.push({i,j+1});
        }
        return res;
    }
};