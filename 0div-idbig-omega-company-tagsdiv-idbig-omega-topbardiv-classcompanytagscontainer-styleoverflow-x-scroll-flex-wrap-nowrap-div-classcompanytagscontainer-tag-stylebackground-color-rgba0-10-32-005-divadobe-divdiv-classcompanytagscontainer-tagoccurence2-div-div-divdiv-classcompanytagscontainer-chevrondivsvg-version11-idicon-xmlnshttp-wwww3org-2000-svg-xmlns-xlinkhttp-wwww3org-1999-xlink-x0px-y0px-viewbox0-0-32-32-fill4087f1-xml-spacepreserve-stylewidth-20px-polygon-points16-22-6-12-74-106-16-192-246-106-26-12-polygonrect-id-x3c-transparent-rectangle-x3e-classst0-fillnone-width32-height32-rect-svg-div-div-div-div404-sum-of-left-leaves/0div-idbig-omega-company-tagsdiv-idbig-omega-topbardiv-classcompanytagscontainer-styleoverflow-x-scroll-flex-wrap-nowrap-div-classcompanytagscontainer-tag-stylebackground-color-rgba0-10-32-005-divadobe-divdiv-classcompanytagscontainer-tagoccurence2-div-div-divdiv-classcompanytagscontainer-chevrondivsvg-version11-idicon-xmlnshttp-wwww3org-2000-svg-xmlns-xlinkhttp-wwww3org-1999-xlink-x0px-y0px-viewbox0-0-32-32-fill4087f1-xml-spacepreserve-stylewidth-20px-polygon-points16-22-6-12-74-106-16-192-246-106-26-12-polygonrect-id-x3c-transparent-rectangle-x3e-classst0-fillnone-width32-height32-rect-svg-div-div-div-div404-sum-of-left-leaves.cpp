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
    int solve(TreeNode* root, bool isLeft)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
        {
            if(isLeft)
                return root->val;
            else
                return 0;   
        }
        int leftSum  = solve(root->left, true);
        int rightSum = solve(root->right, false);
        
        return leftSum + rightSum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right)
            return 0;
        
        return solve(root->left, true) + solve(root->right, false);
    }
};