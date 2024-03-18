class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;  
     for(auto it: points)
     
         pq.push({it[0],it[1]});
     
   int start=pq.top().first;
   int end=pq.top().second;
   int cnt=1;
   while(!pq.empty())
   {
       int st=pq.top().first;
       int en=pq.top().second;
       pq.pop();
       if(st<=end&&en>=start) 
       {
           start=max(start,st);
           end=min(end,en);
       }
       else
       {
       
             start=min(st,end);
             end=en; 
           cnt++;
       }
   }
   return cnt;
    }
};