class Solution {
private:
    vector<int> rank;
    vector<int> parent;

    int find(int x) {
        // If x is itself parent
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        // If both parent are equal then are already in same set
        if(x_parent == y_parent)
            return;
        
        // Merge by rank, higher rank will be parent
        if(rank[x] < rank[y])
            swap(x_parent, y_parent);
        
        // Always x has higher rank
        parent[y_parent] = x_parent;

        // If the ranks are same , then increase rank
        if(rank[x] == rank[y])
            rank[x]++;
    }



public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        rank.resize(n, 0);
        parent.resize(n);

        // Make everyone its own parent
        for(int i=0; i< n; i++)
            parent[i] = i;

        // Create sets of allowedSwaps
        for(auto pair : allowedSwaps)
            Union(pair[0], pair[1]);

        // Elements and their freqency within each set or parent
        unordered_map<int, unordered_map<int, int>> sets;
        for(int i=0; i<n; i++) {
            int i_parent = find(i);
            sets[i_parent][source[i]]++;
        }

        int hummingDistance = 0;
        for(int i=0; i<n; i++) {
            int i_parent = find(i);
            if(sets[i_parent][target[i]] > 0)
                sets[i_parent][target[i]]--;
            else
                hummingDistance++;
        }

        return hummingDistance;
    }
};