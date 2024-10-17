class Solution {
public:
    int maximumSwap(int num) {
        
        string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            int curr=s[i]-'0';
            int id=i;
            int mx=curr;
            for(int j=i+1;j<s.size();j++)
            {
                if(s[j]-'0'>=mx)
                {
                    mx=s[j]-'0';
                    id=j;
                }
            }
            //cout<<i<<" "<<id<<endl;
            if(id!=i && mx!=curr)
            {
                swap(s[i],s[id]);
                break;
            }
        }
        return stoi(s);
    }
};