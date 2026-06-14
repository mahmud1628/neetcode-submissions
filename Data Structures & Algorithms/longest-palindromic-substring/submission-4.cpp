class Solution {
    void search(string & s, int left, int right, int & max_length, string & longest) {
        while(true) {
            if(left < 0) break;
            if(right == s.size()) break;
            if(s[left] != s[right]) break;
            left--;
            right++;
        }
        left++;
        right--;
        int length = right - left + 1;
        if(length > max_length) {
            max_length = length;
            longest = s.substr(left, length);
        }
    }
public:
    string longestPalindrome(string s) {
        int max_length = -1;
        string longest = "";
        for(int i = 0; i < s.size(); i++) {
            search(s, i, i, max_length, longest);
            search(s, i, i + 1, max_length, longest);
        }
        return longest;
    }
};
