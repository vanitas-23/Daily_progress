class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> cnt;
        for (int j = 0; j < n; j ++) {
            cnt.push_back(0);
            
            int x = nums[j];
            while (j < n && x == nums[j]) j ++, cnt.back()++;
            j --;
        }
        sort (cnt.begin(), cnt.end());
        
        n = cnt[0];
        while (n) {
            int grps = 0;
            bool no = false;
            
            for (auto i : cnt) {
                int div = i/n;
                int rem = i%n;
                if (rem > div) {
                    no = true;
                    continue;
                }
                
                int x_1 = rem;
                int x = div - rem;
                x_1 += (x / (n+1)) * n;
                x    = (x % (n+1));

                grps += (x + x_1);
                // int div_1 = i/(n+1);
                // int rem_1 = i%(n+1);
                // grps += div_1;
                // if (rem_1 > 0) grps ++;                
            }
            if (!no) return grps;
            n --;
        }
        return -1;
    }
};