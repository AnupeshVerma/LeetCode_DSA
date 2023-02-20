class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Naived Approach
        
        vector<int> ans(nums.size());
        int pos_ind=0, neg_ind=1;
        
        for(auto i : nums)
            if(i>0)
            {
                ans[pos_ind] = i;
                pos_ind+=2;
            }
            else
            {
                ans[neg_ind] = i;
                neg_ind+=2;
            }
        return ans;
    }
};