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
    
     void findLeftValue(TreeNode* root, int level, int &maxLevel, int &result) {
        if (root == nullptr) 
            return;

        if (level > maxLevel) {
            result = root->val;
            maxLevel = level;
        }

        findLeftValue(root->left, level + 1, maxLevel, result);
        findLeftValue(root->right, level + 1, maxLevel, result);
    }

    int findBottomLeftValue(TreeNode* root) {
         int maxLevel = -1;
        int result = 0;
        findLeftValue(root, 0, maxLevel, result);
        return result;
    }
};