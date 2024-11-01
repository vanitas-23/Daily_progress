class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int cnt=0;
        char pre='$';
        for(char c:s)
        {
            if(cnt==0)
            {
                res+=c;
                pre=c;
                cnt=1;
            }
            else
            {
                if(pre==c)
                {
                    if(cnt==1)
                    res+=c,cnt++;
                }
                else
                res+=c,cnt=1,pre=c;
            }
        }
        return res;
    }
};