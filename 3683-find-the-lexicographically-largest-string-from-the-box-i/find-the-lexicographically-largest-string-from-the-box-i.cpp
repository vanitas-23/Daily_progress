class Solution {
public:
    string answerString(string word, int nf) {
        string temp="";
        int n=word.size();
        if(nf==1)
        return word;
        for(int i=0;i<n-nf+1;i++)
        temp+=word[i];
        string ans=temp;
        for(int i=n-nf+1;i<n;i++)
        {
            temp+=word[i];
            temp.erase(0,1);
            ans=max(ans,temp);
        }
        while(temp.size()>0)
        {
            temp.erase(0,1);
            ans=max(ans,temp);
        }
        return ans;
    }
};