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
    
    string bfs(TreeNode* root)
    {
        string ans="";
        queue<pair<TreeNode*, string>>q;
        
        q.push({root, string(1, root->val+'a')});
        
        while(!q.empty())
        {
            auto[node, temp] = q.front();
            q.pop();
            
            if(!node->left && !node->right)
                if(ans=="" || ans>temp)
                    ans = temp;
            
            if(node->left)  q.push({node->left,  char(node->left->val +'a')+temp});
            if(node->right) q.push({node->right, char(node->right->val+'a')+temp});
        }
        return ans;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        
        return bfs(root);
        
        dfs(root, "");
        return ans;
    }
};