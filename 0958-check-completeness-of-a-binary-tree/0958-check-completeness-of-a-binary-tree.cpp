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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();      
            for(int i=0; i< size; i++)
            {
                auto temp = q.front();
                q.pop();
                if(temp == NULL)
                {
                    flag = false;
                    break;
                }
                if(temp != NULL and flag == false)
                    return false;
                q.push(temp->left); 
                q. push(temp->right); 
            }
        }
        return true;
    }
};