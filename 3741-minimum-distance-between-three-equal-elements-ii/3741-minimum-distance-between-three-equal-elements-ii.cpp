class Solution {
private:
    int n;
    int min_dist = INT_MAX;

    int usingFlag(vector<int>& nums) {
        int temp_dist;

        for(int i=0; i<n-2; i++) {
            int secondOccurrence = false;
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j]) {
                    // If occurred for the second time
                    if(!secondOccurrence) {
                        secondOccurrence = true;
                        continue;
                    }

                    // If occurred more than twice
                    min_dist = min(min_dist, 2*(j - i));
                }
            }
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }

    int usingMaps(vector<int>& nums) {
        unordered_map<int, int> firstOccur;
        unordered_map<int, int> secondOccur;

        for(int i=0; i<n; i++) {
            // if occurred first time, store it
            if(firstOccur.find(nums[i]) == firstOccur.end()) {
                firstOccur[nums[i]] = i;
                continue;
            }
            // If found second time
            if(secondOccur.find(nums[i]) == secondOccur.end()) {
                secondOccur[nums[i]] = i;
                continue;
            }

            // If found more than twice
            min_dist = min(min_dist, 2*(i - firstOccur[nums[i]]));
            // Slide window forward
            firstOccur[nums[i]] = secondOccur[nums[i]];
            secondOccur[nums[i]] = i;
            
        }

        return min_dist == INT_MAX ? -1 : min_dist;
    }


public:
    int minimumDistance(vector<int>& nums) {
        n = nums.size();

        return usingMaps(nums);

        return usingFlag(nums);
    }
};