class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
      //  int n=min(players.size(),trainers.size());
        int left=0;
        int right=0,res=0;
        while(left<players.size() && right<trainers.size()){
            if(players[left]<=trainers[right]){
                res++;left++;right++;
            }
            else{
                right++;
            }
        }

        return res;
        
    }
};