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




class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        if (node==NULL) return NULL;
        
        unordered_map<Node*,Node*>Original_Clone;
        queue<Node*>q;
        
        q.push(node);
        
        Node* temp = new Node(node->val);
        Original_Clone[node]=temp;
        
        while(!q.empty())
        {
            Node* current_o_node = q.front();
            q.pop();
            
            for(auto it :current_o_node->neighbors)
            {
                if(Original_Clone.find(it)==Original_Clone.end())
                {
                    Node*temp = new Node(it->val);
                    Original_Clone[it]=temp;
                    
                    q.push(it);
                }
                //At the same time , We need to also update neighbors array for the clone graph :
                Original_Clone[current_o_node]->neighbors.push_back(Original_Clone[it]);
                
            }
        }
        return Original_Clone[node];
        
        

        

    }
};




// unordered_map<Node*, Node*> visited;
//         queue<Node*> q;
        
//         q.push(node);

//         // Clone the root node and store it in visited map
//         Node* temp = new Node(node->val);
//         visited[node] = temp;

//         while (!q.empty()) {
//             Node* currNode = q.front();
//             q.pop();

//             for (Node* neighbor : currNode->neighbors) 
//             {
//                 if (visited.find(neighbor) == visited.end()) {
//                     // Clone the neighbor node and store it in visited map
//                     temp = new Node(neighbor->val);
//                     visited[neighbor] = temp;
//                     q.push(neighbor);
//                 }
//                 // Connect the clone of the current node to the clone of the neighbor
//                 visited[currNode]->neighbors.push_back(visited[neighbor]);
//             }
//         }

//         return visited[node];



