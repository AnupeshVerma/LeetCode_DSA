class Solution {
private:
    int sumOfDigits(int n) {
        int sum = 0;

        while(n) {
            sum += n%10;
            n = n/10;
        }
        return sum;
    }


    int bruteForce(vector<int> & nums, int n) {
        int maxSum = -1;
        int currSum= -1;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(sumOfDigits(nums[i]) == sumOfDigits(nums[j]))
                    currSum = nums[i] + nums[j];
                
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }


    int usingSorting(vector<int>& nums, int n) {
        vector<pair<int, int>> digitSumPair;

        for(int num : nums)
            digitSumPair.push_back({sumOfDigits(num), num});

        sort(digitSumPair.begin(),digitSumPair.end());

        int maxSum = -1;
        int currSum= -1;

        for(int i=1; i<n; i++) {
            int currPairSum = digitSumPair[i].first;
            int prevPairSum = digitSumPair[i-1].first;

            if(currPairSum == prevPairSum)
                currSum = digitSumPair[i].second + digitSumPair[i-1].second;
            
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }


public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        return usingSorting(nums, n);

        return bruteForce(nums, n);
    }
};