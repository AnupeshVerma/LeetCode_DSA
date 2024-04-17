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
    string ans = "";
private:
    void dfs(TreeNode* root, string temp)
    {
        if(!root)
            return;
        
        temp = char(root->val + 'a') + temp;
        if(!root->left && !root->right)
            if(ans=="" || ans>temp)
                ans = temp;
        
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        
        dfs(root, "");
        return ans;
    }
};