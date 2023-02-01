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
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        if(!root->left)
            return 1+minDepth(root->right);
        else if(!root->right)
            return 1 + minDepth(root->left);
        
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        
        return 1 + min(lh, rh);
    }
};