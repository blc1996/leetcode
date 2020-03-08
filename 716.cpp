class MaxStack {
public:
    stack<int> st;
    stack<int> maxSt;
    /** initialize your data structure here. */
    MaxStack() {
        st = stack<int>();
        maxSt = stack<int>();
    }
    
    void push(int x) {
        st.push(x);
        if(maxSt.empty() || x > maxSt.top()){
            maxSt.push(x);
        }else{
            maxSt.push(maxSt.top());
        }
    }
    
    int pop() {
        int temp = st.top();
        st.pop();
        maxSt.pop();
        return temp;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return maxSt.top();
    }
    
    int popMax() {
        stack<int> tempSt;
        int maxNum = maxSt.top();
        bool removeFlag = true;
        while(removeFlag){
            if(st.top() != maxSt.top()){
                tempSt.push(st.top());
                
            }else{
                removeFlag = false;
            }
            st.pop();
            maxSt.pop();
        }
        while(!tempSt.empty()){
            push(tempSt.top());
            tempSt.pop();
        }
        return maxNum;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */