class Solution {
private:
    int usingPriorityQueue(vector<int> nums, vector<vector<int>> queries, int n, int q) {
        priority_queue<int> endings;
        priority_queue<int, vector<int>, greater<int>> pastEndings;

        int j=0;
        int usedCount = 0;
        for(int i=0; i<n; i++) {
            // Put all the endings of queries start from current index
            while(j < q && queries[j][0] == i) {
                endings.push(queries[j][1]);
                j++;
            }

            // Check if past queries impacted the current i
            nums[i] -= pastEndings.size();
            while(nums[i] > 0 && !endings.empty() && endings.top() >= i) {
                int ending = endings.top();
                endings.pop();
                pastEndings.push(ending);
                usedCount++;
                nums[i]--;
            }
            if(nums[i] > 0)
                return -1;
            
            // Clear the outdated indices
            while(!pastEndings.empty() && pastEndings.top() <= i)
                pastEndings.pop();
        }
        return q-usedCount;
    }

public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        sort(queries.begin(), queries.end());

        return usingPriorityQueue(nums, queries, n, q);
        
        
        priority_queue<int> pq;
        vector<int>deltaArray(n+1, 0);
        int ops = 0;

        for(int i=0, j=0; i<n; i++) {
            ops += deltaArray[i];

            while(j < q && queries[j][0] == i) {
                pq.push(queries[j][1]);
                ++j;
            }

            while(ops < nums[i] && !pq.empty() && pq.top() >= i) {
                ops +=1;
                deltaArray[pq.top() + 1] -= 1;
                pq.pop();
            }
            if(ops < nums[i])
                return -1;
        }
        return pq.size();
    }
};