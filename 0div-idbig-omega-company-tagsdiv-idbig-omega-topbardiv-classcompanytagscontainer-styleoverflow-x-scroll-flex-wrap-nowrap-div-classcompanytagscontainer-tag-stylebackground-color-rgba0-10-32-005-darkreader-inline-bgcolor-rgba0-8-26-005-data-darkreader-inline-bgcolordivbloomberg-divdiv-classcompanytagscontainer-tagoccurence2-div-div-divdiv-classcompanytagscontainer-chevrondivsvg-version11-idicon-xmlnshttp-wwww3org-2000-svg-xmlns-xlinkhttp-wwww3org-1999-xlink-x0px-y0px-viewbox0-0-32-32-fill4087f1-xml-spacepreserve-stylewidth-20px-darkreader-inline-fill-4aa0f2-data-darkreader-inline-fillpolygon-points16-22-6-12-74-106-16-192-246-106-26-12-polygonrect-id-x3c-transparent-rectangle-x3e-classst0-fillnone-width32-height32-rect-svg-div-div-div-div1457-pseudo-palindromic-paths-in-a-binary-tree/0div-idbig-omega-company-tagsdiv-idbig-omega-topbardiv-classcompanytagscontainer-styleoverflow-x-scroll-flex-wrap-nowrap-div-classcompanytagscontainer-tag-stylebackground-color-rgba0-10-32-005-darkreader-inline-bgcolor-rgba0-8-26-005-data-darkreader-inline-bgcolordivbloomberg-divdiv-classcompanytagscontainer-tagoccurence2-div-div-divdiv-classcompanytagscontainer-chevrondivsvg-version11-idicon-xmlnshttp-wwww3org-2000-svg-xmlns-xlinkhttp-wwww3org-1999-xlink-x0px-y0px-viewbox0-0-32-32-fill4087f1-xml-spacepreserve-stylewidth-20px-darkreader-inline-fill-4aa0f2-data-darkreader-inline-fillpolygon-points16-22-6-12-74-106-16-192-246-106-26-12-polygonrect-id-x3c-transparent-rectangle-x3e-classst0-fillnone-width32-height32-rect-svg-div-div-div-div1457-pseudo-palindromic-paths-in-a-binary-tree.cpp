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
       bool checkPalindrome(unordered_map<int, int>& freq) {
        int oddCount = 0;
        for (auto& a : freq) 
        {
            if (a.second % 2 != 0) 
            {
                oddCount++;
                if (oddCount > 1) 
                    return false;
            }
        }
        return true;
    }
    
    int paths(TreeNode* root, unordered_map<int, int> &freq)
    {
       if(root)
       {
           
            freq[root->val]++;
            if(!root->left && !root->right){
                int ans = checkPalindrome(freq);
                freq[root->val]--;
                return ans;
            }
                
                
           
            int left = paths(root->left, freq);
            int right= paths(root->right, freq);

            freq[root->val]--;
            if(freq[root->val]==0) freq.erase(root->val);

            return left + right;
       }
        return 0;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> freq;
        return paths(root, freq);
    }
};