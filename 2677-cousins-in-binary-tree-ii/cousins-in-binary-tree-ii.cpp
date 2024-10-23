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
    vector<int> levelSum(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sum = 0, size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(sum);
        }
        return ans;
    }
    
    
    TreeNode* bfs(TreeNode* root) {
        vector<int> level_sum = levelSum(root);
        
        queue<TreeNode*> q;
        int level = 1;
        q.push(root);
        root->val = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                int sibling_sum = 0;
                sibling_sum += temp->left  ? temp->left->val  : 0;
                sibling_sum += temp->right ? temp->right->val : 0;
                
                if(temp->left){
                    temp->left->val = level_sum[level] - sibling_sum;
                    q.push(temp->left);
                }
                if(temp->right){
                    temp->right->val = level_sum[level] - sibling_sum;
                    q.push(temp->right);
                }
            }
            level++;
        }
        return root;
    }
    
    
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root)
            return root;
        
        return bfs(root);
    }
};