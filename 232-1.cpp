class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;

    MyQueue() {
        st = stack<int>();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = st.top();
        st.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        return st.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
