class Solution {
private:
    vector<int> bruteForce(vector<int> digits, int n) {
        unordered_set<int> nums;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    if(i==j || j==k || i==k)
                        continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num >= 100 && num%2 == 0)
                        nums.insert(num);
                }
            }
        }

        // Convert to vector
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());

        return ans;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        return bruteForce(digits, n);
    }
};