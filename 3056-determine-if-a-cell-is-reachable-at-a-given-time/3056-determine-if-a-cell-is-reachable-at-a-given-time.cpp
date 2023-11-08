class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
      int l=abs(fy-sy);
    int h=abs(fx-sx);
    if(l==0 && h==0)
        return t>1 || t==0;
    return max(l,h)<=t;
     
    
    }
};