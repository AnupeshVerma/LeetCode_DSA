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
    
    vector<int> optimised(vector<int>& nums)
    {
        vector<int> ans;
        
        for(auto num : nums)
        {
            // abs(num)-1 is used so it will not overflow if num==n
            if(nums[abs(num)-1] < 0)
                ans.push_back(abs(num));
            
            nums[abs(num)-1] = -nums[abs(num)-1];
        }
        return ans;
    }
    
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // return bruteForce(nums);
        
        return optimised(nums);
    }
};