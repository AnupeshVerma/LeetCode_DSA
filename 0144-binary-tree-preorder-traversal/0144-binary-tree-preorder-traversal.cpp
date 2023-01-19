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
    void pre(TreeNode*root, vector<int> &ans)
    {
        if(root)
        {
            ans.push_back(root->val);
            pre(root->left, ans);
            pre(root->right, ans);
        }
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
         if(!root)
            return ans;
        
        // ---------- RECURSIVE SOLUTION-----------
        //pre(root, ans);
        
        // -----------ITERATIVE SOLUTION-----------
       
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            auto temp = s.top();
            s.pop();
            
            ans.push_back(temp->val);
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
        return ans;
        
    }
};