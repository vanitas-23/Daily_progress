class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        set<pair<int,int>> stp ;
        for(int i = 0 ; i <=k ; i++){
            stp.insert({i,k-i}) ;
            stp.insert({k-i,i}) ;
        }
        
        map<pair<int,int>,int> mp ;
        int ans = 0 ;
        for(auto point : coordinates){
            int x = point[0] , y = point[1] ;
            for(auto prev : stp){
                int first = prev.first^x , second = prev.second^y ;
                if(mp.find({first , second}) != mp.end()){
                    ans += mp[{first,second}] ;
                }
            }
            mp[{x,y}]++;
        }
        return ans ;
    }
};