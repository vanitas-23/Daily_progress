#include<bits/stdc++.h>
class Solution {
    vector<int>adj[26];
    //unordered_map<pair<int,int>,int>mp;
    
public:
     
   
    long long minimumCost(string s, string t, vector<char>& org, vector<char>& ch, vector<int>& cost) {
        vector<vector<long long>>grid(26,vector<long long>(26,1e12));
        for(int i=0;i<org.size();i++)
           grid[org[i]-'a'][ch[i]-'a']=min(cost[i]*1ll,grid[org[i]-'a'][ch[i]-'a']);
        int n=s.size();
        vector<vector<long long>> temp=grid;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                temp[j][k]=min(temp[j][i]+temp[i][k],temp[j][k]);
            }
        }
    }
         long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
                continue;
            
            ans+=temp[s[i]-'a'][t[i]-'a'];
            if(ans>=1e12)
                return -1;
        }
        return ans;
    }
};