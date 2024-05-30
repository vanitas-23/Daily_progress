class Solution {
public:
    int destroyTargets(vector<int>& a, int space) {
      sort(a.begin(), a.end());
      vector<int> b = a;
      map<int, int> cnt;
	  
      int mx = 0;
      for (auto &bi: b) {
        bi -= bi / space * space;
        cnt[bi]++;
        mx = max(mx, cnt[bi]);
      }
	  
      int mn = 2e9;
      for (auto &ai: a) {
        int aii = ai - ai / space * space;
        if (cnt[aii] == mx)
          mn = min(mn, ai);
      }
      return mn;
    }
};