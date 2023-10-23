class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
            vector<int>tab;
       tab.push_back(a[0]);
       int n=a.size();
       for(int i = 1; i < n; i++){
           if(tab[tab.size()-1] < a[i])tab.push_back(a[i]);
           else *lower_bound(tab.begin(), tab.end(), a[i]) = a[i];
       }
       
       return tab.size();
    }
};