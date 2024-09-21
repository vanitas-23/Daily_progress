class Solution {
public:
    vector<int>dig={0,1,2,3,4,5,6,7,8,9};
    vector<int>arr;
    void f(int i,int n)
    {
        for(auto j:dig)
        {
            if(i*10+j==0)
            continue;
            if(i*10+j>n)
            continue;
            arr.push_back(i*10+j);
            f(i*10+j,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        f(0,n);
        return arr;
    }
};