class Solution {
    bool dfs(int node, vector<vector<int>> & neighbors, vector<int> & state) {
        if(state[node] == 1) { // ifwe find something that has been visited on the current path, we have a cycle
            return false;
        }
        if(state[node] == 2) { // if we find some thing that has already been processed, no need to process it anymore 
            return true;
        }

        state[node] = 1; // 1 means it is on the current path
        for(int neighbor : neighbors[node]) {
            bool b = dfs(neighbor, neighbors, state);
            if(!b) {
                return false;
            }
        }
        state[node] = 2; // 2 means it is finished processing and not on the current path

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses, vector<int>());

        for(int i = 0; i < prerequisites.size(); i++) {
            neighbors[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
           bool b = dfs(i, neighbors, state);
           if(!b) return false;
        }

        return true;
    }
};
