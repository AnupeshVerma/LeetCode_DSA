class Solution {
private:
    int n;
    int minDist = INT_MAX;

    int bruteForce(vector<int>& nums) {
        for(int i = 0; i < n-2; i++) {
            bool secondOccurrenceFound = false;
            for(int j = i+1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    if(!secondOccurrenceFound) {
                        secondOccurrenceFound = true;
                        continue;
                    }
                    minDist = min(minDist, 2*(j - i));
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }

    int optimized(vector<int>& nums) {
        unordered_map<int, int> firstOccur;
        unordered_map<int, int> secondOccur;

        for(int i = 0; i < n; i++) {
            if(firstOccur.find(nums[i]) == firstOccur.end()) {
                firstOccur[nums[i]] = i;
                continue;
            }
            if(secondOccur.find(nums[i]) == secondOccur.end()) {
                secondOccur[nums[i]] = i;
                continue;
            }
            minDist = min(minDist, 2*(i - firstOccur[nums[i]]));
            firstOccur[nums[i]] = secondOccur[nums[i]];
            secondOccur[nums[i]] = i;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }

public:
    int minimumDistance(vector<int>& nums) {
        n = nums.size();
        
        return optimized(nums);

        // return bruteForce(nums);
    }
};