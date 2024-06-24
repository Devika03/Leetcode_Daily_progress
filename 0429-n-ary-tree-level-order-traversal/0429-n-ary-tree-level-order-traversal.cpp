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
    void helper(Node* node , vector<vector<int>>&result)
    {
        if(node==NULL)return;
        
        queue<Node*>q;
        q.push(node);
        
        
        while(!q.empty())
        {
            vector<int>ans_temp;
            
            int size = q.size(); //To get the size of the current level. 
            for(int i = 0 ; i<size ; i++)
            {
                Node*temp = q.front();
                
                ans_temp.push_back(temp->val);
                q.pop();
                
                for (auto child : temp->children) 
                {
                    q.push(child);
                }
            }
            result.push_back(ans_temp);
    }
    }

    
    
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>>res;
        helper(root,res);
        return res;
    }
};