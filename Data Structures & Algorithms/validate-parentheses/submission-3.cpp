class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);

            else if(c == ')') {
                if(st.size() == 0) return false;
                if(st.top() != '(') return false;
                st.pop();
            }

            else if(c == '}') {
                if(st.size() == 0) return false;
                if(st.top() != '{') return false;
                st.pop();
            }

            else if(c == ']') {
                if(st.size() == 0) return false;
                if(st.top() != '[') return false;
                st.pop();
            }
        }

        if(st.size() > 0) return false;

        return true;
    }
};
