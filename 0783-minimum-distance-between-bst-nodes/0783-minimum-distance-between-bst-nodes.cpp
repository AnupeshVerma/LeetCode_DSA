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
    vector<int> v;
    void preorder(TreeNode *root)
    {
        if(root)
        {
            v.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        preorder(root);
        int min_diff = INT_MAX;
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<v.size()-1; i++)
            min_diff = min(min_diff, abs(v[i]-v[i+1]));

        return min_diff;
    }
};