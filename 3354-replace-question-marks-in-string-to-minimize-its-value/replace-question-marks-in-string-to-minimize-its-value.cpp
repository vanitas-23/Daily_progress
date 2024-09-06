class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int>arr(26);
        vector<int>marked;
        vector<char>ele;
        int n=s.size();
        for(char c:s)
        if(c!='?')
        arr[c-'a']++;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                int mn=n+1;
                char ch='#';
                for(char c='a';c<='z';c++)
                {
                    if(mn>arr[c-'a'])
                        mn=arr[c-'a'],ch=c;
                }
                s[i]=ch;
                marked.push_back(i);
                ele.push_back(ch);
                arr[ch-'a']++;
            }
        }
        sort(ele.begin(),ele.end());
        int j=0;
        for(auto i:marked)
        s[i]=ele[j++];
        return s;
    }
};