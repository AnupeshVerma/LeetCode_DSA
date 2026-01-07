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
long long mod = 1e9 + 7;
private:
    long long sumOfSubtreeInPlace(TreeNode* root) {
        if(!root)
            return 0;
        root->val += sumOfSubtreeInPlace(root->left) + sumOfSubtreeInPlace(root->right);

        return root->val;
    }


public:
    int maxProduct(TreeNode* root) {
        long long totalSum = sumOfSubtreeInPlace(root);
        long long maxProduct = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            long long currProduct = (totalSum - node->val) * node->val;
            maxProduct = max(maxProduct, currProduct);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return maxProduct % mod;        
    }
};