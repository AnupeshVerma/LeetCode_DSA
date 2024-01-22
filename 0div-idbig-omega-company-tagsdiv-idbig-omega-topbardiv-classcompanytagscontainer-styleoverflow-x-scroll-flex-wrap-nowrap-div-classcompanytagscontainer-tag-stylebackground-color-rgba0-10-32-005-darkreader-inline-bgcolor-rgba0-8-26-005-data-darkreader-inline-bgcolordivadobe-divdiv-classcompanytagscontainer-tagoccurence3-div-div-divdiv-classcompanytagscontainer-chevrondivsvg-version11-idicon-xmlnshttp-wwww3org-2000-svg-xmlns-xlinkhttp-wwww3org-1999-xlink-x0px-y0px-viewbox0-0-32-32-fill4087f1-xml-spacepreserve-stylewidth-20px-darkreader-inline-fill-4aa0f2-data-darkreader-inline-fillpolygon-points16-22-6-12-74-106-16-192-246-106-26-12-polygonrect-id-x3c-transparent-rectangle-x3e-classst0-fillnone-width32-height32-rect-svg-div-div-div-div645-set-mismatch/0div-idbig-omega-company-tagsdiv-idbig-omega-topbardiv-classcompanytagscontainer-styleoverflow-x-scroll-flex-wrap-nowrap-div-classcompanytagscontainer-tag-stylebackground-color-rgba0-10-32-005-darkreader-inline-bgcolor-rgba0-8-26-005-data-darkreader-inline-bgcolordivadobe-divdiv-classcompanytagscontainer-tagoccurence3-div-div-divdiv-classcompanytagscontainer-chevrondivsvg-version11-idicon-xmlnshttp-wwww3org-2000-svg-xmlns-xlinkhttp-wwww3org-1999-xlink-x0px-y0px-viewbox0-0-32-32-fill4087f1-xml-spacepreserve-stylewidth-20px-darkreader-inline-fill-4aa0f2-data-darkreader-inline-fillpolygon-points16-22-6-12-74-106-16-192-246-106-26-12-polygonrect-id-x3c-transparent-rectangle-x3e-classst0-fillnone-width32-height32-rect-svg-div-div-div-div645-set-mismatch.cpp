class Solution {
public:
    vector<int> hashMethod(vector<int> & nums, int n)
    {
        vector<int> hash(n+1, 0);
        vector<int> ans;
        
        for(auto num : nums)
        {
            hash[num]++;
            if(hash[num] == 2)
                ans.push_back(num);
        }
        
        for(int i=1; i<=n; i++)
            if(hash[i] == 0)
                ans. push_back(i);
        
        return ans;
    }
    
    vector<int> bruteForce(vector<int>& nums, int n)
    {
        int missing=0, repeat=0;
        
        sort(nums.begin(), nums.end());        
        for(int i=1; i<=n; i++)
        {
            if(i<n && nums[i-1] == nums[i])
                repeat = nums[i];
            
            if(find(nums.begin(), nums.end(), i) == nums.end())
                missing = i;
        }
        return {repeat, missing};
               
    }
    
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        // return hashMethod(nums, n);
        
        return bruteForce(nums, n);
        
        
       
    }
};