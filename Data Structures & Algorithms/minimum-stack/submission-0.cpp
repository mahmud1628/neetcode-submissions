class MinStack {
    stack<int> st;
    stack<int> minimums;
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(minimums.empty()) {
            minimums.push(val);
            return;
        }
        minimums.push(min(minimums.top(),val));
    }
    
    void pop() {
        if(st.empty()) return;
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
