/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int val, int depth)
    {
        if(!root)
            return;
        
        if(depth == 2)
        {
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = root->left;
            
            TreeNode* newRight = new TreeNode(val);
            newRight->right = root->right;
            
            root->left = newLeft;
            root->right = newRight;
            return;
        }
        solve(root->left, val, depth-1);
        solve(root->right, val, depth-1);
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        solve(root, val, depth);
        return root;
    }
};