class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size()/2;
      unordered_map<int,int> mp1,mp2;
        
      for(auto &i: nums1){
          mp1[i]++;
      }
      for(auto &i: nums2){
          mp2[i]++;
      }
      int u1 =0, u2 =0, cm = 0;
      
      for(auto &i: mp1){
        if(mp2.find(i.first) == mp2.end()) u1++;
        else cm++;      
      }
     
      for(auto &i: mp2){
        if(mp1.find(i.first) == mp1.end()) u2++;
      }
      
      int left1 = max(0,min(m-u1,cm)), left2 = max(0,min(m-u2,cm));
      return min(m,u1) + min(m,u2) + min(left1+left2,cm); 
    }
};