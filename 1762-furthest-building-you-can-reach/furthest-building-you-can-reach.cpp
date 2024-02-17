class Solution {
public:
    bool can_reach(vector<int> &heights, int bricks, int ladders, int target){
        vector<int> jumps;
        for(int i=0; i<target; i++){
            int diff = heights[i+1] - heights[i];
            if(diff > 0) jumps.push_back(diff);
        }
        
        if(jumps.size() <= ladders) return true;
        
        sort(jumps.begin(), jumps.end());

        int jumps_made_using_bricks = jumps.size() - ladders;
        int bricks_needed = accumulate(jumps.begin(), jumps.begin() + jumps_made_using_bricks, 0);

        if(bricks_needed <= bricks) return true;
        return false;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int left = 0, right = n-1, temp = ladders;
        int ans=0;
        while(left <= right){
            int mid = left + (right - left) / 2;
          //  if(mid == n-1) return mid;
            if(can_reach(heights,bricks,ladders,mid))
            left=mid+1;
            else
            right=mid-1;
        }
        return left-1;
    }
};