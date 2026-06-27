class Solution {
    void dfs(int node, vector<vector<int>> & neighbors, vector<bool> & visited) {
        if(visited[node]) return;

        visited[node] = true;

        for(int neighbor : neighbors[node])
            dfs(neighbor, neighbors, visited);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n, vector<int>());

        for(auto edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                dfs(i, neighbors, visited);
                count++;
            }
        }

        return count;
    }
};
