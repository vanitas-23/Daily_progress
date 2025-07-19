class Solution {
public:
    vector<string> removeSubfolders(vector<string>& fol) {
        sort(fol.begin(),fol.end());
        unordered_set<string>st;
        for(auto i:fol)
        {
            string temp="";
            bool b=0;
            for(int j=0;j<i.size();j++)
            {
                temp+=i[j];
                if(j==i.size()-1 || (i[j+1]=='/'))
                if(st.find(temp)!=st.end())
                {
                    b=1;
                    break;
                }
            }
            if(!b)
            st.insert(i);
        }
        vector<string>res(st.begin(),st.end());
        return res;
    }
};