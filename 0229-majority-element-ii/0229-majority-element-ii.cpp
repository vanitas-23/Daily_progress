class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int ele1=0;
     int ele2=0;
     int cnt1=0;
     int cnt2=0;
     for(int i:nums){
          if(i==ele1)
         cnt1++;
         else if(i==ele2)
         cnt2++;
         else if(cnt1==0){
             ele1=i;
             cnt1++;
         }
         else if(cnt2==0){
             ele2=i;
             cnt2++;
         }
        
         else{
             cnt1--;
             cnt2--;
         }
     }
      
        vector<int> res;
        if (count(nums.begin(), nums.end(), ele1) > nums.size() / 3) res.push_back(ele1);
        if (count(nums.begin(), nums.end(), ele2) > nums.size() / 3) res.push_back(ele2);
        if(ele1==ele2 && res.size()>1)
        res.pop_back();
        return res;

    }
};