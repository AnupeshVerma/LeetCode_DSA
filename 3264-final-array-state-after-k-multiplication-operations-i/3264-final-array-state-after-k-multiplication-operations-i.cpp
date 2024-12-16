class Solution {
private:
    vector<int> bruteForce(vector<int> nums, int k, int multiplier, int n) {
        while(k--) {
            // Find the index of minimum value
            int min_index = 0;
            for(int i=1; i<n; i++)
                if(nums[min_index] > nums[i])
                    min_index = i;

            // Replace the minimum value 
            nums[min_index] *= multiplier;;       
        }
        return nums;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        return bruteForce(nums, k, multiplier, n);
    }
};