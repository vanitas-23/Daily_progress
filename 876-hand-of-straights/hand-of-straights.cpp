class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gr) {
        vector<vector<int>>arr;
        int n=hand.size();
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++)
        {
            if(arr.size()==0)
            {
                vector<int>temp;
                temp.push_back(hand[i]);
                arr.push_back(temp);
                continue;
            }
            bool b=0;
            for(auto& x:arr)
            {
                if(x.size()==gr)
                continue;
                if(x.back()+1==hand[i])
                {
                    //cout<<hand[i]<<" "<<x.back()<<endl;
                    x.push_back(hand[i]);
                    
                    b=1;
                    break;
                }
            }
            if(!b)
            {
                vector<int>temp;
                temp.push_back(hand[i]);
                arr.push_back(temp);
            }
        }
        for(auto i:arr)
        {
            if(i.size()!=gr)
            return 0;
        }
        return 1;
    }
};