class Solution {
public:
    
    void f(int room,vector<vector<int>>& rooms,vector<bool>&vis){
        if(vis[room])
            return ;
        vis[room]  =1;
        for(int key:rooms[room]){
            if(vis[key]) continue ;
            f(key,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size()+1,0);
        f(0,rooms,vis);
        return accumulate(vis.begin(),vis.end(),0)==rooms.size();
    }
};