class Solution {
private:
    int bruteForce(vector<int>& originalNums, int k) {
        int totalOps = 0;

        vector<long> nums(originalNums.begin(), originalNums.end());;

        sort(nums.begin(), nums.end());

        while(nums[0] < k) {
            if(nums.size() < 2)
                return -1;

            totalOps++;
            long int newNum = nums[0]*2 + nums[1];
            nums.erase(nums.begin());
            nums[0] = newNum;
            
            sort(nums.begin(), nums.end());
        }
        return totalOps;
    }


    int usingPriorityQueue(vector<int>& nums, int k) {
        int totalOps = 0;
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());

        while(pq.top() < k) {
            totalOps++;
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();

            pq.push(x*2 + y);
        }
        return totalOps;
    }


public:
    int minOperations(vector<int>& nums, int k) {
        return usingPriorityQueue(nums, k);
        
        return bruteForce(nums, k);
    }
};