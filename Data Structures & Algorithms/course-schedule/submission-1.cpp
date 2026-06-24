class Solution {
    bool dfs(int node, vector<vector<int>> & neighbors, vector<bool> & visited) {
        if(visited[node]) return false;

        visited[node] = true;
        for(int neighbor : neighbors[node]) {
            bool b = dfs(neighbor, neighbors, visited);
            if(!b) return false;
        }
        visited[node] = false;

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses, vector<int>());

        for(int i = 0; i < prerequisites.size(); i++) {
            neighbors[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> visited(numCourses, false);

        for(int i = 0; i < numCourses; i++) {
           bool b = dfs(i, neighbors, visited);
           if(!b) return false;
           visited = vector<bool>(numCourses, false);
        }

        return true;
    }
};
