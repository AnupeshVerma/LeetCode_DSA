class Solution {
private:
    int usingSet(vector<int>& nums, int n)
    {
        int count = 0;
        unordered_set<int>st;
        
        for(auto num : nums)
        {
            while(st.find(num) != st.end())
            {
                num++;
                count++;
            }
            st.insert(num);
        }
        
        return count;
    }
    
    int usingSort(vector<int>& nums, int n)
    {
        int count = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1; i<n; i++)
        {
            // If previous term is larger than the current number
            if(nums[i-1] >= nums[i])
            {
                count += nums[i-1] + 1 - nums[i];
                nums[i] = nums[i-1] + 1;
            }
        }
        return count;
    }
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        // return usingSet(nums, n);
        
        return usingSort(nums, n);
    }
};