class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        int idx;
        for(int i=0; i<q; i++){
            int l = queries[i][0]; 
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            idx = l;
            while(idx <= r) {
                nums[idx] = (1ll * nums[idx] * v) % MOD;
                idx += k;
            }
        }

        // Find XOR of final array
        int ans = 0;
        for(int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};