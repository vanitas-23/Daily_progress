class Solution {
public: 
    int miceAndCheese(vector<int>& v1, vector<int>& v2, int k) {
      int n = v1.size(), ans = 0;
      vector<pair<int, int>> vp(n);
      for(int i = 0; i < n; i++){
        vp[i] = {v1[i] - v2[i], i};
      }
      sort(vp.begin(), vp.end(), greater<>());
      for(int i = 0; i < n; i++){
        int idx = vp[i].second;
        if(i < k) ans += v1[idx];
        else ans += v2[idx];
      }
      return ans;
    }
};