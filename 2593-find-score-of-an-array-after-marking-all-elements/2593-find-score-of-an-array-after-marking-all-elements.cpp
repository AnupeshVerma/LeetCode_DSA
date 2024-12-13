class Solution {
private:
    long long bruteForce(vector<int> nums, int n) {
        long long score = 0;
        int min_ele = INT_MAX - 1;

        while (true) {
            auto min_iterator = min_element(nums.begin(), nums.end());
            min_ele = *min_iterator;

            if (min_ele == INT_MAX)
                break;

            int min_ele_index = distance(nums.begin(), min_iterator);
            score += min_ele;

            nums[min_ele_index] = INT_MAX;
            if (min_ele_index + 1 < n)
                nums[min_ele_index + 1] = INT_MAX;
            if (min_ele_index - 1 >= 0)
                nums[min_ele_index - 1] = INT_MAX;
        }
        return score;
    }


    long long usingSorting(vector<int> nums, int n) {
        long long score = 0;

        vector<pair<int, int>> sorted;
        for(int i=0; i<n; i++)
            sorted.push_back(make_pair(nums[i], i));

        sort(sorted.begin(), sorted.end());
        vector<bool> marked(n, false);

        for(int i=0; i<n; i++) {
            int index = sorted[i].second;
            if(marked[index])
                continue;
            score += sorted[i].first;
            cout<<sorted[i].first<<" ";

            // Mark as done
            marked[index] = true;
            if(index-1 >= 0)
                marked[index-1] = true;
            if(index+1 < n)
                marked[index+1] = true;
        }
        return score;
    }

public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        return usingSorting(nums, n);

        return bruteForce(nums, n);
    }
};