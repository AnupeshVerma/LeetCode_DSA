class Solution {
private:
    vector<int> bruteForce(vector<int>& nums)
    {
        vector<int> ans;
        unordered_map<int, int> freq;
        
        for(auto num : nums)
        {
            freq[num]++;
            if(freq[num] > 1)
                ans.push_back(num);
        }
        
        return ans;
    }
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        return bruteForce(nums);
    }
};