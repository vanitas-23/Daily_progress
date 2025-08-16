class Solution {
public:
    int maximum69Number (int n) {
    int k=0;
    string s=to_string(n);
    reverse(s.begin(),s.end());
    cout<<s;
    n=0;
    int size=s.length();
    for(int i=size-1;i>=0;i--){
        if(s[i]=='9' || k==1){
            n=n*10+(s[i]-'0');
        }
        else{
             n=n*10+9;
             k++;
        }
    }  
    return n; 
    }
};