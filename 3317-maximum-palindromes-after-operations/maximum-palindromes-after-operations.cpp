class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>arr(26);
        int n=words.size();
        for(int i=0;i<n;i++)
        for(char c:words[i])
        arr[c-'a']++;
        auto cmp=[](string a,string b)
        {
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),cmp);
        int ans=0;
        int even=0;
        int odd=0;
        for(auto i:arr)
        {
            if(i%2)
            even+=(i-1),odd++;
            else
            even+=i;
        }
        for(int i=0;i<n;i++){
            if(words[i].size()%2){
                if(even>=words[i].size()-1){
                    if(even == (words[i].size()-1) && odd<1)continue;
                    ans++;
                    if(odd>=1)odd--;
                    else {even-=2;odd++;}

                    even-=((words[i].size()-1));
                }
            }
            else{
                if(even>=(words[i].size())){
                    
                    ans++;
                    even-=(words[i].size());
                }
            }
        }

        return ans;
    }
};