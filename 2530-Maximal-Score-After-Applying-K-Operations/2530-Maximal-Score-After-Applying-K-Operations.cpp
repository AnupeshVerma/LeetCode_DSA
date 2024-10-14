class Solution {
private:
    long long bruteForce(vector<int>& nums, int k, int n) {
        long long score = 0;
        
        while(k--) {
            int curr_max = INT_MIN;
            int max_ind = 0;
            for(int i=0; i<n; i++) {
                if(curr_max < nums[i]){
                    curr_max = nums[i];
                    max_ind = i;
                }
            }
            score += nums[max_ind];
            nums[max_ind] = ceil(nums[max_ind]*1.0/3);
        }
        return score;
    }
    
    
    long long usingPriorityQueue(vector<int>& nums, int k, int n) {
        long long int score = 0;
        priority_queue<int>pq;
        
        for(int num : nums)
            pq.push(num);
        
        while(k--) {
            int max_ele = pq.top();
            score += max_ele;
            pq.pop();
            pq.push(ceil(max_ele*1.0/3));
        }
        return score;
    }
    
    
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        
        // return bruteForce(nums, k, n);
        
        return usingPriorityQueue(nums, k, n);
    }
};
