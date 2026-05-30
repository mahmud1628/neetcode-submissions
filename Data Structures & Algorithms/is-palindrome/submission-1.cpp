class Solution {
    bool isAlphaNum(char c) {
        if(c >= 48 && c <= 57) return true;
        if(c >= 65 && c <= 90) return true;
        if(c >= 97 && c <= 122) return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int left, right;
        left = 0;
        right = s.size() - 1;

        while(left <= right) {
            if(!isAlphaNum(s[left])) {
                left++;
                continue;
            }
            if(!isAlphaNum(s[right])) {
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};
