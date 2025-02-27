class Solution {
private:
    int bruteForce(vector<int>& arr, int n) {
        unordered_set<int> numSet(arr.begin(), arr.end());

        int maxLen = 0;
        // Try all possible first two numbers of sequence
        for (int start = 0; start < n; ++start) {
            for (int next = start + 1; next < n; ++next) {
                // Start with first two numbers
                int prev = arr[next];
                int curr = arr[start] + arr[next];
                int len = 2;

                // Keep finding next Fibonacci number
                while (numSet.find(curr) != numSet.end()) {
                    // Update values for next iteration
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = max(maxLen, ++len);
                }
            }
        }
        return maxLen;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        return bruteForce(arr, n);
    }
};