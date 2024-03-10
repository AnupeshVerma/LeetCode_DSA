class Solution {
private:
    vector<int> bruteForce(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int>st, ansSet;
        
        for(auto num:nums1)
            st.insert(num);
        
        for(auto num:nums2)
            if(st.find(num) != st.end())
                ansSet.insert(num);
        
        vector<int>ans(ansSet.begin(), ansSet.end());
        return ans;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        
        return bruteForce(nums1, nums2);
    }
};