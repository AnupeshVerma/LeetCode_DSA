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
    void in(TreeNode *root, vector<int>&ans)
    {
        if(root)
        {
            in(root->left, ans);
            ans.push_back(root->val);
            in(root->right, ans);              
            
        }
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        //-----------------Recursive Solution---------
        //in(root, ans);
        
        //-----------------ITERATIVE SOLUTION---------
        stack<TreeNode*>s;
        
        while(true)
        {
            if(root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                if(s.empty())
                    break;
                
                root = s.top();
                s.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};