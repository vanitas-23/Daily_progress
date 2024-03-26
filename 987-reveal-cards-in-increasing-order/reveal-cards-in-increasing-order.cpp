class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int>dq;
        sort(deck.begin(),deck.end());
        int j=deck.size()-1;
        dq.push_back(deck[j--]);
        while(j>=0)
        {
            int x=dq.back();
            dq.pop_back();
            dq.push_front(x);
            dq.push_front(deck[j--]);
        }
        vector<int>res;
        for(int i:dq)
        res.push_back(i);
        return res;
    }
};