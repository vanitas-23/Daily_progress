class MedianFinder {
public:
    priority_queue<int>fst;
    priority_queue<int,vector<int>,greater<int>>snd;
    int n=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(fst.size()==0)
        fst.push(num);
        else if(num>fst.top())
        {
            snd.push(num);
            while(snd.size()>=fst.size()+1)
            fst.push(snd.top()),snd.pop();
        }
        else
        {
            fst.push(num);
            while(fst.size()>snd.size()+1)
            snd.push(fst.top()),fst.pop();
        }
        n++;
    }
    
    double findMedian() {
        if(n%2)
        return fst.top();
        return (fst.top()+snd.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */