class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s) {
            if(ch=='(' || ch=='{' || ch=='[') {
                st.push(ch);
            }
            else if(ch == ')') {
                if(st.size() == 0) {
                    return false;
                }
                if(st.top() == '(') {
                    st.pop();
                }
                else return false;
            }
            else if(ch == '}') {
                if(st.size() == 0) {
                    return false;
                }
                if(st.top() == '{') {
                    st.pop();
                }
                else return false;
            }
            else if(ch == ']') {
                if(st.size() == 0) {
                    return false;
                }
                if(st.top() == '[') {
                    st.pop();
                }
                else return false;
            }
        }
        if(st.size()) {
            return false;
        }
        return true;
    }
};