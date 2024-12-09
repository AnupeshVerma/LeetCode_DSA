class Solution {
private:
    vector<bool> bruteForce(vector<int>& nums, vector<vector<int>>& queries, int n) {
        vector<bool> ans;

        for(auto query : queries) {
            int from = query[0], to = query[1];
            int i = from;
            bool flag = true;
            for(i=from; i<to; i++) {
                if(nums[i]%2 == nums[i+1]%2) {
                    ans.push_back(false);
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(true);
        }
        return ans;
    }

bool binarySearch(int start, int end, vector<int>& corrupted_index) {
    int left = 0;
    int right = corrupted_index.size() - 1;


    while(left <= right) {
        int mid = left + (right - left)/2;
        int ind = corrupted_index[mid];

        if(ind < start)
            left = mid + 1;
        else if(ind > end)
            right = mid - 1;
        else
            return true;
    }
    return false;
}

    vector<bool> usingBinarySearch(vector<int>& nums, vector<vector<int>>& queries, int n) {


        vector<bool> ans;
        vector<int> corrupted_index;

        // Collect the corrupted_index
        for(int i=1; i<n; i++) {
            if(nums[i]%2 == nums[i-1]%2)
                corrupted_index.push_back(i);
        }

        for(auto query : queries) {
            int from = query[0], to = query[1];

            // Apply binary search to check corrupted_index
            bool is_corrupted = binarySearch(from+1, to, corrupted_index);
            if(is_corrupted)
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }


public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        return usingBinarySearch(nums, queries, n);

        return bruteForce(nums, queries, n);
    }
};