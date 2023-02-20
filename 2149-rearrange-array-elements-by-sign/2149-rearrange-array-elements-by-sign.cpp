class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Naived Approach
        
        vector<int> pos, neg;
        for(auto i : nums)
            if(i>0)
                pos.push_back(i);
            else
                neg.push_back(i);
        
        for(int i=0, ind=0; i<nums.size(); i=i+2)
        {
            nums[i] = pos[ind];
            nums[i+1] = neg[ind];
            ind++;
        }
        return nums;
    }
};