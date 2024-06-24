/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    void helper(Node* node , int &depth)
    {
        if(node==NULL)return;
        
        queue<Node*>q;
        q.push(node);
        
        while(!q.empty())
        {
            
            
            int size = q.size(); //To get the size of the current level. 
            for(int i = 0 ; i<size ; i++)
            {
                Node*temp = q.front();
                q.pop();
                
                for (auto child : temp->children) 
                {
                    q.push(child);
                }
        }
            depth++;
    }
    }
    int maxDepth(Node* root) 
    {
        int d=0;
        helper(root,d);
        
        return d;
    }
};