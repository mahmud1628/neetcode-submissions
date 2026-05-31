class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int end = 1;
        int max_length = 0;
        int max_frequency = 1;
        unordered_map<char, int> frequencies;
        frequencies[s[start]] = 1;
        int n = s.size();

        while(end < n) {
            frequencies[s[end]]++;
            max_frequency = max(max_frequency, frequencies[s[end]]);

            int other_chars = end - start + 1 - max_frequency;

            if(other_chars <= k) {
                max_length = max(max_length, end - start + 1);
            }
            else {
                frequencies[s[start]]--;
                start++;
            }
            end++;
        }

        return max_length;
    }
};
