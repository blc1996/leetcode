class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> elemSt;
    stack<int> minSt;

    MinStack() {
        elemSt = stack<int>();
        minSt = stack<int>();
    }
    
    void push(int x) {
        elemSt.push(x);
        if(minSt.empty() || x < minSt.top()){
            minSt.push(x);
        }else{
            minSt.push(minSt.top());
        }
    }
    
    void pop() {
        elemSt.pop();
        minSt.pop();
    }
    
    int top() {
        return elemSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */