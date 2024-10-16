class Solution {
public:
    string longestDiverseString(int a, int b, int ch) {
        priority_queue<pair<int,char>>pq;
        if(a>0)
        pq.push({a,'a'});
        if(b>0)
        pq.push({b,'b'});
        if(ch>0)
        pq.push({ch,'c'});
        string s="";
        int isl=0;
        char c='&';
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            if(isl==2 && x.second==c && pq.size()>0)
            {
                auto y=pq.top();
                pq.pop();
                pq.push(x);
                isl=1;
                c=y.second;
                s+=y.second;
                if(y.first>1)
                pq.push({y.first-1,y.second});
            }
            else if(x.second!=c)
            {
                s+=x.second;
                isl=1;
                if(x.first>1)
                pq.push({x.first-1,x.second});
                c=x.second;
            }
            else if(isl!=2)
            {
                s+=x.second;
                isl++;
                if(x.first>1)
                pq.push({x.first-1,x.second});
                c=x.second;
            }
            else
            break;
        }
        return s;
    }
};