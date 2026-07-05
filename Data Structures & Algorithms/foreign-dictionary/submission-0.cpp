class Solution {
    // We only need the words to determine the edge.
    bool add_edge(string & a, string & b, unordered_map<char, vector<char>> & adj_list) {
        int l = min(a.size(), b.size());

        for (int t = 0; t < l; t++) {
            // Found the first difference, create a directed edge
            if (a[t] != b[t]) {
                adj_list[a[t]].push_back(b[t]);
                return true; 
            }
        }

        // If we didn't find any differences, but the first word is longer, 
        // it's an invalid dictionary order (e.g., "abcd" before "abc")
        if (a.size() > b.size()) {
            return false;
        }
        
        return true;
    }

    bool dfs(char c, unordered_map<char, vector<char>> & adj_list, unordered_map<char, int> & state, string & reverse_order) {
        if (state.find(c) != state.end()) {
            if (state[c] == 1) return false; // Already visited and safe
            if (state[c] == 2) return true;  // Cycle detected!
        }

        state[c] = 2; // Mark as currently visiting

        for (auto nei : adj_list[c]) {
            bool cycle = dfs(nei, adj_list, state, reverse_order);
            if (cycle) return true;
        }

        state[c] = 1; // Mark as fully visited
        reverse_order.push_back(c);
        return false;
    }

public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj_list;

        // Initialize the graph with all unique characters first.
        // This ensures isolated letters (not involved in any edges) are still in our result.
        for (const string& word : words) {
            for (char c : word) {
                adj_list[c] = vector<char>();
            }
        }

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            bool valid_order = add_edge(words[i], words[i + 1], adj_list);
            if (!valid_order) return "";
        }

        unordered_map<char, int> state; 
        string reverse_order = "";

        // Run DFS on every node in the graph
        for (auto i : adj_list) {
            if (state.find(i.first) == state.end()) {
                bool cycle = dfs(i.first, adj_list, state, reverse_order);
                if (cycle) return "";
            }
        }

        // Reverse the post-order to get the valid topological sort

        reverse(reverse_order.begin(), reverse_order.end());

        return reverse_order;
    }
};