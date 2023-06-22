{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     leftView(root);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    
    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};*/

void leftView(Node *root)
{
   // Max height of tree assumed to be 100
   //Therefore for skew tree, max levels = 100
   bool levels[202] = {false};
   printLeftview(levels,root,0);
}

void printLeftview(bool *level_vis, TreeNode*root, int curr)
{
    if(root==NULL)
        return;
    
    if(levels[curr]==false)
    {
        levels[curr] = true;
        cout<<root->data<<" ";
    }
    printLeftview(levels,root->left,curr+1);    //left child called
    printLeftview(levels,root->right,curr+1);   //right child called
}
