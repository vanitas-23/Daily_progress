class Solution {
public:
    string inv(string s)
    {
        string res="";
        for(auto i:s)
        if(i=='0')
        res+='1';
        else
        res+='0';
        return res;
    }
    char findKthBit(int n, int k) {
        if(n==1)
        return '0';
        string s1="0";
        for(int i=1;i<n;i++)
        {
            string temp=s1;
            s1+='1';
            reverse(temp.begin(),temp.end());
            s1+=inv(temp);
        }
        return s1[k-1];
    }
};