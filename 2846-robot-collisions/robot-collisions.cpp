class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        vector<pair<int,pair<int,char>>>arr;
        int n=pos.size();
        for(int i=0;i<n;i++)
        arr.push_back({pos[i],{h[i],dir[i]}});
        sort(arr.begin(),arr.end());
        map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[pos[i]]=i;
        for(int i=0;i<n;i++)
        {
            pos[i]=arr[i].first;
            h[i]=arr[i].second.first;
            dir[i]=arr[i].second.second;
        }
        stack<pair<char,pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({dir[i],{h[i],pos[i]}});
                continue;
            }
            if(dir[i]=='R')
            st.push({dir[i],{h[i],pos[i]}});
            else
            {
                int curr=h[i];
                bool b=0;
                while(st.size() && st.top().first=='R' && !b)
                {
                    
                    auto x=st.top();
                    st.pop();
                    if(x.second.first<curr)
                    curr--;
                    else if(x.second.first==curr)
                    {
                        b=1;
                    }
                    else
                    {
                        st.push({x.first,{x.second.first-1,x.second.second}});
                        b=1;
                    }
                }
                if(!b)
                st.push({dir[i],{curr,pos[i]}});
            }
        }
        vector<pair<int,int>>ans;
        while(!st.empty())
        {
            auto x=st.top();
            st.pop();
            ans.push_back({x.second.second,x.second.first});
        }
        auto cmp=[&mp](pair<int,int> a,pair<int,int> b){
            return mp[a.first]<mp[b.first];
        };
        sort(ans.begin(),ans.end(),cmp);
        vector<int>res;
        for(auto i:ans)
        res.push_back(i.second);
        return res;
    }
};