class Solution {
private:
    int usingSet(vector<int>& nums) {
        int max_count = 0;
        unordered_set<long long> st(nums.begin(), nums.end());
        
        for (int num : nums) {
            int count = 1;
            long long square = (long long)num;
            
            while (st.find(square * square) != st.end()) {
                square = square * square;
                count++;
            }
            
            max_count = max(max_count, count);
        }
        
        return max_count > 1 ? max_count : -1;  // If no streak of length > 1, return -1
    }

public:
    int longestSquareStreak(vector<int>& nums) {
        return usingSet(nums);
    }
};
