class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    float time[dist.size()];

    for(int i=0; i<dist.size(); i++)
    {
        time[i] = float(dist[i]) / speed[i];
    }

    sort(time,time+dist.size());
    int counter = 0;
    int c = 0;
    for(int i=0; i<dist.size(); i++)
    {   
        if(time[i] - c > 0)
        {counter++; c++;}
        else
        {return counter;}
    }

    return counter;

}
};