class Solution {
    bool hasCycle(int node, int parent, vector<vector<int>> & neighbors, vector<bool> & visited) {
        if(visited[node]) {
            return true;
        }

        visited[node] = true;

        for(int neighbor : neighbors[node]) {
            if(neighbor == parent) continue;
            if(hasCycle(neighbor, node, neighbors, visited)) return true;
        }

        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n, vector<int>());

        for(auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            neighbors[a].push_back(b);
            neighbors[b].push_back(a);
        }

        vector<bool> visited(n, false);

        if(hasCycle(0, -1, neighbors, visited)) return false;

        for(bool b : visited)
            if(!b) return false;
        
        return true;
    }
};
