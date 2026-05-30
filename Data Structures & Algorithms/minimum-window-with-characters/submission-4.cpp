class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char,int> t_map;
        for(char c : t) {
            if(t_map.find(c) == t_map.end()) {
                t_map[c] = 1;
            }
            else {
                t_map[c]++;
            }
        }
        int left = 0, right = 0;
        int map_initial_size = t_map.size();
        int res_left = 0, res_right = 0;
        int min_length = INT_MAX;
        while(right < s.size()) {
            if(t_map.find(s[right]) == t_map.end()) {
                right++;
            }
            else {
                t_map[s[right]]--;
                if(t_map[s[right]] == 0) {
                    map_initial_size--;
                }
                if(!map_initial_size) {
                    again:
                    while(t_map.find(s[left]) == t_map.end()) {
                        left++;
                    }
                    if(t_map[s[left]] < 0) {
                        t_map[s[left]]++;
                        left++;
                        goto again;
                    }
                    if(min_length > right - left + 1) {
                        res_left = left;
                        res_right = right;
                        min_length = right - left + 1;
                    }
                    t_map[s[left]]++;
                    if(t_map[s[left]] == 1)
                        map_initial_size++;
                    left++;
                    while(t_map.find(s[left]) == t_map.end()) {
                        left++;
                    }
                }
                right++;
            }
        }
        if(res_left == res_right) {
            if(t.size() > 1 || t[0] != s[res_left]) {
                return "";
            }
        }
        return s.substr(res_left,min_length);
    }
};
