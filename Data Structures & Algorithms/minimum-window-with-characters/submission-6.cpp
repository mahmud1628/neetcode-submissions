class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char, int> t_map;
        for(char c : t) t_map[c]++;

        int left = 0, right = 0;
        int map_size = t_map.size();
        int min_length = INT_MAX;

        int min_window_left = 0;
        int min_window_right = 0;

        while(right < s.size()) {
            if(t_map.find(s[right]) != t_map.end()) {
                t_map[s[right]]--;
                if(t_map[s[right]] == 0) map_size--;

                if(map_size == 0) {
                    again:
                    while(t_map.find(s[left]) == t_map.end()) left++;

                    if(t_map[s[left]] < 0) {
                        t_map[s[left]]++;
                        left++;
                        goto again;
                    }

                    if(min_length > right - left + 1) {
                        min_window_left = left;
                        min_window_right = right;
                        min_length = right - left + 1;
                    }

                    t_map[s[left]]++;
                    if(t_map[s[left]] == 1) map_size++;
                    left++;
                    while(left < s.size() && t_map.find(s[left]) == t_map.end()) left++;
                } 
            }
            right++;
        }

        if(min_window_left == min_window_right) {
            if(t.size() > 1 || t[0] != s[min_window_left]) {
                return "";
            }
        }

        return s.substr(min_window_left, min_length);

    }
};
