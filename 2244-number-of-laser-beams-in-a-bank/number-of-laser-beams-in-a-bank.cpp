class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int curr=0;
        int prev=0;
        int res=0;
        for(auto i:bank){
            int cnt=0;
            for(char c:i)
            if(c=='1')
            cnt++;
            if(cnt==0)
            continue;
            if(curr==0){
            curr=cnt;continue;}
            prev=curr;
            curr=cnt;
            res+=curr*prev;
        }
        
        return res;

    }
};