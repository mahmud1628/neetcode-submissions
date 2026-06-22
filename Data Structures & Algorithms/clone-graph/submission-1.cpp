class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node *, Node *> copies; // original node -> cloned node 

        copies[node] = new Node(node->val); // copy the root node 

        queue<Node *> q; // stores original nodes for bfs
        q.push(node);

        while(!q.empty()) {
            Node * curr = q.front();
            q.pop();

            // check the neighbors
            for(Node * neighbor : curr->neighbors) {
                // check if this neighbor is already cloned or not 
                if(copies.find(neighbor) == copies.end()) {
                    Node * copy = new Node(neighbor->val); // copy it
                    copies[neighbor] = copy;

                    q.push(neighbor); 
                }

                // add the copy of the neighbor to the neighbor set of the copy of the curr  
                copies[curr]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};