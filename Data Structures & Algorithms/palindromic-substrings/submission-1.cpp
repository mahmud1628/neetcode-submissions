class Solution {
    // This function finds all the odd length palindromes treating the the `middle` as the center of the palindrome
    int findOddPalindromes(string s, int middle) {
        int count = 1; // any character itself is a palindrome
        int left = middle - 1;
        int right = middle + 1;
        count += countPalindromes(s, left, right);
        return count;
    }

    // this function finds all the even length palindromes treating `middle_left` as the index of the left character at the center of the palindrme 
    int findEvenPalindromes(string s, int middle_left) {
        int left = middle_left;
        int right = middle_left + 1;
        return countPalindromes(s, left, right);
    }

    int countPalindromes(string s, int left, int right) {
        int count = 0;
        while(true) {
            if(left < 0) break;
            if(right >= s.size()) break;

            if(s[left] != s[right]) break;

            count++;
            left--;
            right++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            count += findOddPalindromes(s, i);
            count += findEvenPalindromes(s, i);
        }
        return count;
    }
};
