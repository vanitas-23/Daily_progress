class Solution {
public:
    int f(int i,int n,vector<string>& words,vector<int> arr,vector<int>& score)
    {
        if(i==n)
        return 0;
        int nt=f(i+1,n,words,arr,score);
        int t=0;
        vector<int>temp=arr;
        for(char c:words[i])
        if(arr[c-'a']==0){
        //cout<<c<<" "<<i<<endl;
        return nt;}
        else
        arr[c-'a']--;
        int val=0;
        for(char c:words[i])
        val+=score[c-'a'];
        
        t=val+f(i+1,n,words,arr,score);
        arr=temp;
        return max(t,nt);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>arr(26);
        for(char c:letters)
        arr[c-'a']++;
        int n=words.size();
        return f(0,n,words,arr,score);
    }
};