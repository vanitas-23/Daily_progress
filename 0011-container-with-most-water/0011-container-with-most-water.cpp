class Solution {
public:
    int maxArea(vector<int>& height) {
        int r=height.size()-1;
        int l=0;
        int ans=0;
        while(l<r){
           ans=max(ans,(r-l)*min(height[l],height[r]));
           if(height[l]<height[r])
           l++;
           else
           r--;
        }
        return ans;
    }
};