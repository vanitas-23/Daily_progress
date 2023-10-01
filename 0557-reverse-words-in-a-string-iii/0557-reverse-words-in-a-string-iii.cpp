class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string temp="";
        for(char c:s){
            if(c==' ')
            {
                reverse(temp.begin(),temp.end());
                res+=temp;
                res+=c;
                temp="";
            }
            else
            temp+=c;
        }
        reverse(temp.begin(),temp.end());
                res+=temp;
        
        return res;
    }
};