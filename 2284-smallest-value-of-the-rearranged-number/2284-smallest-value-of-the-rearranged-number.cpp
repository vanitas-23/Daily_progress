class Solution {
public:
long long smallestNumber(long long num) {

    if(!num)
        return 0;
        
    return num < 0 ? -helper1(-num) : helper2(num);
}

long long helper1(long long num)
{
    int no_of_zeros = 0;
    priority_queue<int> pq;
    while(num)
    {
        if(num % 10) 
            pq.push(num % 10);
        else
            no_of_zeros++;
        
        num /= 10;
    }
    
    while(!pq.empty())
        num = num * 10 + pq.top(), pq.pop();
    
    while(no_of_zeros--)
        num *= 10;
    
    return num;
}

long long helper2(long long num)
{
    int no_of_zeros = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(num)
    {
        if(num % 10) 
            pq.push(num % 10);
        else
            no_of_zeros++;
        
        num /= 10;
    }
    
    num = pq.top(), pq.pop();
    while(no_of_zeros--)
        num *= 10;
    
    while(!pq.empty())
        num = num * 10 + pq.top(), pq.pop();
    
    return num;
}
};