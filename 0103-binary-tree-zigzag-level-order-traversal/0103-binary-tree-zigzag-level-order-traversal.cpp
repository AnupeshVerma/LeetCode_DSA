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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        int layer =0;
        q.push(root);
        
        while(!q.empty())
        {
            layer++;
            vector<int> v;
            int size = q.size();
            
            for(int i=0; i<size; i++)
            {
                auto temp = q.front();
                v.push_back(temp->val);
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(layer%2==0)
                reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};