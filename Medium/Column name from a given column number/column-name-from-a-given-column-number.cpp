//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        unordered_map<int,char>mp;
        for(int i=1;i<26;i++)
        mp[i]='A'+i-1;
        mp[0]='Z';
        string res="";
        while(n>0){
            
           res+=mp[n%26];
           if(n%26==0)
           n--;
           n/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends