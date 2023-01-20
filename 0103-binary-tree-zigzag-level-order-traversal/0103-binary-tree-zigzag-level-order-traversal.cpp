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
        int layer_no = 1;
        
        q.push(root);
        
        while(!q.empty())
        {
            layer_no++;
            int size = q.size();
            vector<int> v;
            
            for(int i=0; i<size; i++)
            {
               
                TreeNode* temp = q.front();
                q.pop();
                
                v.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        
            if(layer_no %2 != 0)
                reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
}
};