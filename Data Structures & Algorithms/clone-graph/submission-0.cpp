class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Maps original node -> cloned node
        unordered_map<Node*, Node*> copies;

        // Clone the root node and register it in our map
        copies[node] = new Node(node->val);

        queue<Node*> q; // for bfs
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Iterate through all neighbors of the current original node
            for (Node* neighbor : curr->neighbors) {
                // If the neighbor hasn't been cloned yet
                if (copies.find(neighbor) == copies.end()) {
                    // 1. Clone it
                    copies[neighbor] = new Node(neighbor->val);
                    // 2. Push the ORIGINAL neighbor to the queue to process its connections later
                    q.push(neighbor);
                }
                
                // Connect the cloned current node to the cloned neighbor
                copies[curr]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};