class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        int out = temp.top();
        temp.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return out;
    }

    /** Get the front element. */
    int peek() {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        int out = temp.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return out;
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
