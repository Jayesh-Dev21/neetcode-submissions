class MinStack {
public:
    stack<int> ss;
    std::stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        ss.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }
        else{
            minStack.push(min(val,minStack.top()));
        }
    }
    
    void pop() {
        ss.pop();
        minStack.pop();
    }
    
    int top() {
        return ss.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
