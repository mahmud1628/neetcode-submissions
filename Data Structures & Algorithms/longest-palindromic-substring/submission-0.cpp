class Solution {
    // checks whether the subtring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int max_length = -1;
        string longest = "";

        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(isPalindrome(s, i , j)) {
                    if(j - i + 1 > max_length) {
                        max_length = j - i + 1;
                        longest = s.substr(i, max_length);
                    }
                }
            }
        }
        return longest;
    }
};
