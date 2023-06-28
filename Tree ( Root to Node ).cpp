#include <bits/stdc++.h>
vector<int>Solution(TreeNode*Root , int node)
{
    vector<int>arr;
    if(Root == NULL) return arr;
    getPath(Root, arr ,node );
    retun arr;
}
bool getPath(TreeNode*Root , vector<int> &arr, int x)
{
    if(!Root) return False;//If Root == NULL , Then False . 
    arr.push_back(Root->val);
    
    if(Root->val == x) return True;
    //Otherwise 
    if( getPath(Root->left , arr, x) || getPath(Root->right , arr , x)) return True;//If any of the paths are returning Trure , You will return T. 
    arr.pop_back();//Otherwise
    return False;

}