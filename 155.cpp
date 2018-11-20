class MinStack {
public:
    /** initialize your data structure here. */
    int minVal;
    vector<int> st;

    MinStack() {
        minVal = INT_MAX;
        st = vector<int>();
    }

    void push(int x) {
        st.push_back(x);
        minVal = min(x, minVal);
    }

    void pop() {
        if(minVal == st[st.size() - 1]){
            minVal = INT_MAX;
            for(int i = 0; i < st.size() - 1; i++)
                minVal = min(st[i], minVal);
        }
        st.pop_back();
    }

    int top() {
        return st[st.size() - 1];
    }

    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
