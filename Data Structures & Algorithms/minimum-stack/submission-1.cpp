class MinStack {
    stack<int> st;
    stack<int> minimums;
public:
    MinStack() {
        st.push(INT_MAX);
        minimums.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        minimums.push(min(minimums.top(),val));
    }
    
    void pop() {
        if(st.size() == 1) return;
        st.pop();
        minimums.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minimums.top();
    }
};
