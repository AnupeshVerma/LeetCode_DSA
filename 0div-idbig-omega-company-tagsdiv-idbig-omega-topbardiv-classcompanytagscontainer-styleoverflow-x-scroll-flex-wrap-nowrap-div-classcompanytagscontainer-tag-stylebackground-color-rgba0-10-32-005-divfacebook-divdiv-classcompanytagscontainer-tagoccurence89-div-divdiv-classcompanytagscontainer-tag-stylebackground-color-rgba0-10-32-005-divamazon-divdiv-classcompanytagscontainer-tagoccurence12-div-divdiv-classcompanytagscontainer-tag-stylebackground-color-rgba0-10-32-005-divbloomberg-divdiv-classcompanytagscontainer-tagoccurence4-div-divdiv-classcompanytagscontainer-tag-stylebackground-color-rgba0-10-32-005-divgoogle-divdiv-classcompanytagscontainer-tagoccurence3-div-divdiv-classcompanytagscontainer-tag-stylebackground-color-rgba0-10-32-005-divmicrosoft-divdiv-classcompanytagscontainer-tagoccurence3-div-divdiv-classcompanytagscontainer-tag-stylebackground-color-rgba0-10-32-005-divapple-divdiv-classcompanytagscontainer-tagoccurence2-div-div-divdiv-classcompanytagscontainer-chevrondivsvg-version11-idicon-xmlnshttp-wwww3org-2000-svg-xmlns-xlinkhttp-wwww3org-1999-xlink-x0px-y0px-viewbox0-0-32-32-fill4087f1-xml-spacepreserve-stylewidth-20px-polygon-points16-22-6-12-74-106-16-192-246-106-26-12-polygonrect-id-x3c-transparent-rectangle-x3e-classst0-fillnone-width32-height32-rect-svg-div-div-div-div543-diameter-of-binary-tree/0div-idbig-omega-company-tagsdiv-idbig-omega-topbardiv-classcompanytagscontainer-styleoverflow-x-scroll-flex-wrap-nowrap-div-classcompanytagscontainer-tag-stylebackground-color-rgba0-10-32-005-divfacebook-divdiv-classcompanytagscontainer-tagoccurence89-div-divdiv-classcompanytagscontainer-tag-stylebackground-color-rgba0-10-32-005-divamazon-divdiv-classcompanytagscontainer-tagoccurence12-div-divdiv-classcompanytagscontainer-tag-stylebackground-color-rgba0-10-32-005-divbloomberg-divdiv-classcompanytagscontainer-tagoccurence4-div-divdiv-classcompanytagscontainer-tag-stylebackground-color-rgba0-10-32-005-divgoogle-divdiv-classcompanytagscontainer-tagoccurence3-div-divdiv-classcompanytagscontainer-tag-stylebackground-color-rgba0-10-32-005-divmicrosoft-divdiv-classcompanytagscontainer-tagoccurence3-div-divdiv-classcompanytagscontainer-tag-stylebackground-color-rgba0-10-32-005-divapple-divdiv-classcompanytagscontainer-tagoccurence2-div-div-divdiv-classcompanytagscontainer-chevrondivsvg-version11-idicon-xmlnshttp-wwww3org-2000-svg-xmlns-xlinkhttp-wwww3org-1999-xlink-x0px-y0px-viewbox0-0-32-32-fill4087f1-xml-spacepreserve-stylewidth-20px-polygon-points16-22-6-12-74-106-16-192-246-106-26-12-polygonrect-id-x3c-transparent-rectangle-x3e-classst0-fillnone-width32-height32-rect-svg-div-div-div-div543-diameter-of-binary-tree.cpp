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
    int dia =0;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int lh = height(root->left);    // Height of left tree
        int rh = height(root->right);   // Height of right tree
        
        // edge between root and root->left isn't included that's why not subtract 1 form lh to find the total edges 
        int edges = lh + rh;         
        dia = max(edges, dia);
        
        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        
        return dia;
    }
};