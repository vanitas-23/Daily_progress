class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>inD1;
        vector<int>inD2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                if(inD1.size()==0)
                inD1.push_back(0);
                else
                inD1.push_back(inD1.back()+1);
            }
            else
            {
                if(inD2.size()==0)
                inD2.push_back(0);
                else
                inD2.push_back(inD2.back()+1);
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            pq1.push({inD1[j++],nums[i]});
            else
            pq2.push({inD2[k++],nums[i]});
        }

    
        vector<int>res;
        while(!pq1.empty() || !pq2.empty())
        {
            auto x=pq1.top();
            pq1.pop();
            auto y=pq2.top();
            pq2.pop();
            res.push_back(x.second);
            res.push_back(y.second);
        }
        return res;
    }
};