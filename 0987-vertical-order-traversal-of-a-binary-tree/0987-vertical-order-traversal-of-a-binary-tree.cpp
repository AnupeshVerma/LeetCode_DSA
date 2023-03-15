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
    map<int, map<int, multiset<int>>> mp;
    void preorder(TreeNode*root, int vertical, int level)
    {
        if(!root)
            return;
        mp[vertical][level].insert(root->val);
        
        preorder(root->left, vertical-1, level+1);
        preorder(root->right, vertical+1, level+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
       
        preorder(root, 0, 0);
        
        for(auto i : mp)
        {
            vector<int> temp;
            for(auto j:i.second)
            {
                for(auto k: j.second)
                    temp.push_back(k);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};