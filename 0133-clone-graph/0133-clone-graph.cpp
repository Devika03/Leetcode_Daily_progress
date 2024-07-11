/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/




class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);

        // Clone the root node and store it in visited map
        Node* temp = new Node(node->val);
        visited[node] = temp;

        while (!q.empty()) {
            Node* currNode = q.front();
            q.pop();

            for (Node* neighbor : currNode->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor node and store it in visited map
                    temp = new Node(neighbor->val);
                    visited[neighbor] = temp;
                    q.push(neighbor);
                }
                // Connect the clone of the current node to the clone of the neighbor
                visited[currNode]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};
