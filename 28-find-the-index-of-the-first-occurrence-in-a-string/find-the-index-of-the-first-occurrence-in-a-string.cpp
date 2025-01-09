class Solution {
public:
    int strStr(string h, string nn) {
        int n=h.size();
        int m=nn.size();
        string temp=h.substr(0,m);
        if(temp==nn) return 0;
        for(int i=m;i<n;i++){
            temp.push_back(h[i]);
            temp.erase(0,1);
            if(temp==nn)
            return i-m+1;
        }
        return -1;
    }
};