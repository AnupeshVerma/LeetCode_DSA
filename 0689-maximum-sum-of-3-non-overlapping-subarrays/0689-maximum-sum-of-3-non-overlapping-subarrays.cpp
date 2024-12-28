class Solution {
private:
    int dp(vector<int>& sums, int k, int idx, int count, vector<vector<int>>& memo) {
        // If three subarrays are counted
        if(count == 0)
            return 0;

        if(idx >= sums.size())
            return count > 0 ? INT_MIN : 0;
        
        if(memo[idx][count] != -1)
            return memo[idx][count];

        int include = sums[idx] + dp(sums, k, idx+k, count-1, memo);
        int not_include = dp(sums, k, idx+1, count, memo);

        return memo[idx][count] = max(include, not_include);
    }

    void dfs(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo, vector<int>& indices) {
        if(rem == 0 || idx > sums.size())
            return;
        
        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        // Choose path that gave optimal result in DP
        if (withCurrent >= skipCurrent) {  // Take current subarray
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        } else {  // Skip current subarray
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }


public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Calculate the sum of all subarrays of k length
        vector<int> sums(n-k+1);
        int windowSum = 0;
        for(int i=0; i<k; i++)
            windowSum += nums[i];
        sums[0] = windowSum;

        for(int i=k; i<n; i++) {
            windowSum = windowSum - nums[i-k] + nums[i];
            sums[i-k+1] = windowSum;
        }

        vector<vector<int>> memo(n, vector<int>(4, -1));
        vector<int> indices;

        dp(sums, k, 0, 3, memo);

        dfs(sums, k, 0, 3, memo, indices);

        return indices;
    }
};