class Solution {
    // search odd palindromes considering the `middle` as the index of the center of a palindrome
    void searchOddPalindromes(string & s, int middle, int & max_length, string & longest) {
        int left = middle;
        int right = middle; // a chracter itself is a palindrome, so setting left and right at the same place so that at least we have a palindrome of length 1

        search(s, left, right, max_length, longest);
    }

    // search even palindromes considering the `middle_left` as the idnex of the left character as the center of a palindrome
    void searchEvenPalindromes(string & s, int middle_left, int & max_length, string & longest) {
        int left = middle_left;
        int right = middle_left + 1;

        search(s, left, right, max_length, longest);
    }

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
            searchOddPalindromes(s, i, max_length, longest);
            searchEvenPalindromes(s, i, max_length, longest);
        }
        return longest;
    }
};
