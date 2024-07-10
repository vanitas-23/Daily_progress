class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr=0;
        for(auto i:logs)
        {
            if(i=="./")
            continue;
            if(i=="../")
            {
                if(curr!=0)
                    curr--;
            }
            else
            curr++;
        }
        return curr;
    }
};