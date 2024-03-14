class Solution {
private:
    int bruteForce(vector<int>&nums, int goal, int n)
    {
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                int sum = 0;
                for(int k=i; k<=j; k++)
                    sum += nums[k];
                
                if(sum == goal)
                    count++;
            }
        }
        return count;
    }
    
    int prefixSum(vector<int>& nums, int goal, int n)
    {
        int count=0, sum=0;
        unordered_map<int, int> prefixSum;
        
        for(int num : nums)
        {
            sum += num;
            if(sum == goal)
                count++;
            
            if(prefixSum.find(sum - goal) != prefixSum.end())
                count += prefixSum[sum-goal];
            
            prefixSum[sum]++;
        }
        return count;
    }
    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        // return bruteForce(nums, goal, n);
        
        return prefixSum(nums, goal, n);
    }
};