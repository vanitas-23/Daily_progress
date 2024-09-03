class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        unordered_set<int> s;
        for(auto &i: nums1){
            mp1[i]++;
        }
        for(auto &i: nums2){
            mp2[i]++;
        }
        int a = 0, b = 0,c=0,n=nums1.size(),x;
        for(auto &i: mp1){
            a += (i.second-1);
        }for(auto &i: mp2){
            b += (i.second-1);
        }for(auto &i: mp1){
            if(mp2.count(i.first)){
                c++;
            }
        }
        if(a==0&&b==0&&c==0)return min(n,2*n-c);
        if(a>=n/2&&b>=n/2){
            return 2*n-a-b-c;
        }else if(a>=n/2 && b<n/2){
            if(b+c>=n/2)return 2*n-a-b-c;
            else return 2*n-a-n/2;
        }else if(a<n/2 && b>=n/2){
            if(a+c>=n/2)return 2*n-a-b-c;
            else return 2*n-b-n/2;
        }
        if(a+b+c>=n)return 2*n-a-b-c;
        if(a<=n/2){
            x = n/2-a;
            a += min(x,c);
            c = min(0,c-x);
        }
        if(b<=n/2&&c>0){
            x = n/2-b;
            b += min(x,c);
            c = min(0,c-x);
        }
        return min(2*n-a-b-c,n);
    }
};