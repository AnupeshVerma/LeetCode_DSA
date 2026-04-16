class Solution {
private:
    int n;

    vector<int> causeTLE(vector<int>& nums, vector<int>& queries) {
        for(int &q : queries) {
            int min_dist = INT_MAX;
            int target = nums[q];

            for(int i=1; i<n; i++) {
                int leftIndex  = (q + i) % n;
                int rightIndex = (q - i + n) % n;
                
                if(nums[leftIndex] == target || nums[rightIndex] == target) {
                    min_dist = min(min_dist, i);
                    break;
                }
            }
            q = min_dist == INT_MAX ? -1 : min_dist;
        }

        return queries;
    }


    vector<int> usingMap(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> store;
        vector<int> ans;

        // Store values and indices in the map
        for(int i=0; i<n; i++)
            store[nums[i]].push_back(i);

        // Simulate each query
        for(int &q : queries) {
            vector<int> &indices = store[nums[q]];

            int size = indices.size();

            // If the value occurs only once
            if(size == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();
            int min_dist = INT_MAX;

            // Left neighbor
            int left = indices[(pos - 1 + size) % size];
            int dl = abs(q - left);
            min_dist = min(min_dist, min(dl, n - dl));

            // Right neighbor
            int right = indices[(pos + 1) % size];
            int dr = abs(q - right);
            min_dist = min(min_dist, min(dr, n - dr));

            ans.push_back(min_dist);

        }
        return ans;

    }


public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        n = nums.size();

        return usingMap(nums, queries);

        return causeTLE(nums, queries);
    }
};