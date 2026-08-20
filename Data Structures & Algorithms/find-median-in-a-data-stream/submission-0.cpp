class MedianFinder {
    priority_queue<int, vector<int>, less<int>> s;
    priority_queue<int, vector<int>, greater<int>> l;
public:
    MedianFinder() {}
    
    void addNum(int n) {
        s.push(n);
        if(!l.empty() && s.top()>l.top()) {l.push(s.top()); s.pop();}
        if(s.size() > l.size() + 1) {l.push(s.top()); s.pop();}
        if(l.size() > s.size() + 1) {s.push(l.top()); l.pop();}
    }
    
    double findMedian() {
        if(s.size()==l.size()) return (l.top()+s.top()) / 2.0;
        if(s.size()>l.size()) return s.top() / 1.0;
        else return l.top() / 1.0;
    }
};
