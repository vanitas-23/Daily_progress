//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int cnt=mp[str[0]];
        int n=str.size();
        for(int i=1;i<n;i++){
            //cout<<"hi";
            if(mp[str[i]]>mp[str[i-1]] && (str[i-1]=='I' || str[i-1]=='X' || str[i-1]=='C')){
                cnt+=mp[str[i]]-mp[str[i-1]];
                cnt-=mp[str[i-1]];
            }
            
            else
            cnt+=mp[str[i]];
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends