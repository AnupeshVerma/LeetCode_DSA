class Solution {
private:
    int shortestDistanceUsingBFS(int n, vector<vector<int>> adjList) {
        vector<int> visited(n, false);
        vector<int> distance(n, INT_MAX);
        queue<int> q;

        visited[0] = true;
        distance[0] = 0;
        q.push(0);

        int level  = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int node = q.front();
                q.pop();

                if(node == n-1)
                    return level;
                // Iterate over all neighbours
                for(int neighbour : adjList[node]) {
                    if(!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
            level++;
        }
        return -1;
    }


public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adjList(n);

        // Initialize adjList
        for(int i=0; i<n; i++)
            adjList[i].push_back(i+1);

        // Find distance after every road addition
        for(vector<int> query : queries) {
            adjList[query[0]].push_back(query[1]);
            answer.push_back(shortestDistanceUsingBFS(n, adjList));
        }

        return answer;
    }
};