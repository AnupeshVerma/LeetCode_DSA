class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        sort(queries.begin(), queries.end());

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
                deltaArray[pq.top() + 1] -=1;
                pq.pop();
            }
            if(ops < nums[i])
                return -1;
        }
        return pq.size();
    }
};