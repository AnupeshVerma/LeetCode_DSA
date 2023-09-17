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
    int ans = 0;
    int sum_count(TreeNode *root, int &count)
    {
        if(root)
        {
            count++;
            int leftSum  = sum_count(root->left,  count);
            int rightSum = sum_count(root->right, count);
            return root->val + leftSum + rightSum;
        }
        return 0;
    }
    
    void preorder(TreeNode* root)
    {
        if(root)
        {
            int count=0;
            int sum = sum_count(root, count);
            int avg = sum/count;
            if(avg == root->val)
                ans++;
            
            preorder(root->left);
            preorder(root->right);
        }
    }
public:
    int averageOfSubtree(TreeNode* root) {
        preorder(root);
        
        return ans;
    }
};