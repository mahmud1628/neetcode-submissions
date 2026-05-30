class Solution {
    bool valid_char(char c) {
        if(((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))) {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left <= right) {
            if(valid_char(s[left]) && valid_char(s[right])) {
                if(tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                else {
                    left++;
                    right--;
                }
            }
            else if(!valid_char(s[left])) {
                left++;
            }
            else {
                right--;
            }
        }
        return true;
    }
};