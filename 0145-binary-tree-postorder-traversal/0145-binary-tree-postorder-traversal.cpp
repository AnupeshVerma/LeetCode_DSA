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
    void post(TreeNode*root, vector<int>&ans)
    {
        if(root)
        {
            post(root->left, ans);
            post(root->right, ans);
            ans.push_back(root->val);
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        
        //----------------RECURSIVE SOLUTION---------
        //post(root, ans);
        //return ans;
        
        //-----------ITERATIVE SOLUTION (2 Stacks)-------------
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            TreeNode* temp = s1.top();
            s1.pop();
            
            s2.push(temp);
            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
            
        }
        while(!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};