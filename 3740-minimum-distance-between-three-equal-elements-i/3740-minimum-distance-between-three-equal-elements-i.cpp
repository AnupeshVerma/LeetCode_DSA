class Solution {
private:
    int n;
    int min_dist = INT_MAX;
    
    int bruteForce(vector<int>& nums) {
        int temp_dist;
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                if(nums[i] == nums[j]) {
                    for(int k=j+1; k<n; k++) {
                        if(nums[k] == nums[j]) {
                            temp_dist = abs(i-j) + abs(j - k) + abs(k - i);
                            min_dist = min(min_dist, temp_dist);
                        }
                    }
                }
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
public:
    int minimumDistance(vector<int>& nums) {
        n = nums.size();

        return bruteForce(nums);
    }
};