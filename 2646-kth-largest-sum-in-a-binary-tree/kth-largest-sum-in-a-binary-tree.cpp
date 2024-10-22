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
    long long bfs(TreeNode* root, int k) {
        vector<long> level_sum;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            long sum = 0, size=q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                
            }
            cout<<sum<<" ";
            level_sum.push_back(sum);
        }
        if(k > level_sum.size())
            return -1;
        
        sort(level_sum.begin(), level_sum.end());
        return level_sum[level_sum.size()-k];    
    }
    
    
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        return bfs(root, k);
    }
};