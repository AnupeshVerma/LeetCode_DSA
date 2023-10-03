class Solution {
private:
    int solution1(vector<int>&nums)
    {
        int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i] == nums[j])
                    ans++;
        
        return ans;
    }
public:
    int numIdenticalPairs(vector<int>& nums) {
        
//         O[n^2]
        return solution1(nums);
    }
};