class Solution {
int n1, n2;
vector<int> nums1, nums2;
vector<vector<int>> memo;

private:
    int dp(int i, int j) {
        if(i == n1 || j == n2)
            return -1e9;

        if(memo[i][j] != INT_MIN)
            return  memo[i][j];
        
        int takeAndContinue = nums1[i] * nums2[j] + dp(i+1, j+1);
        int takeAndEnd = nums1[i] * nums2[j];
        int skipNums1 = dp(i+1, j);
        int skipNums2 = dp(i, j+1);

        return memo[i][j] = max({takeAndContinue, takeAndEnd, skipNums1, skipNums2});
    }

public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        
        n1 = nums1.size();
        n2 = nums2.size();

        memo.assign(n1, vector<int>(n2, INT_MIN));
        return dp(0, 0);
    }
};