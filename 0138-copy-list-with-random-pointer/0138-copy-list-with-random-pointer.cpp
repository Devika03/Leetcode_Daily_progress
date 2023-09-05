/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> newMap;
        newMap[NULL] = NULL;
        unordered_map<Node*, vector<Node*>> randomWait;
        Node* previous = nullptr;
        Node* current = head;
        while (current != NULL){
            // Create our new node
            Node* x = new Node(current->val);
            newMap[current] = x;

            // Set our random or set that we are waiting for our random
            if (newMap[current->random]){ // Our new random already exists--use it
                x->random = newMap[current->random];
            }
            else {
                // Our X is waiting for current->random to be added--join the queue
                randomWait[current->random].push_back(x);
            }

            // for every node that is waiting for our current node as "random", set random
            for (auto node : randomWait[current]){
                node->random = x;
            }

            if (previous){
                previous->next = x; // set next for our previous new node

            }
            previous = x;
            current = current->next;
        }
        return newMap[head];
        
        
    }
};