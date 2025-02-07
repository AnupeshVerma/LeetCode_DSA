class Solution {
private:
    vector<int> bruteForce(int limit, vector<vector<int>>& queries, int n) {
        vector<int> ans(n);
        unordered_map<int, int>colorMap;
        vector<int> ballArray(limit + 1);

        for(int i=0; i<n; i++) {
            int ball = queries[i][0];
            int color= queries[i][1];

            if(ballArray[ball] != 0) {
                int prevColor = ballArray[ball];
                colorMap[prevColor]--;
                if(colorMap[prevColor] == 0)
                    colorMap.erase(prevColor);
            }

            ballArray[ball] = color;
            colorMap[color]++;

            ans[i] = colorMap.size();
        }
        return ans;
    }


    vector<int> twoMaps(int limit, vector<vector<int>>& queries, int n) {
        vector<int> ans(n);
        unordered_map<int, int> colorMap, ballMap;

        for(int i=0; i<n; i++) {
            int ball = queries[i][0];
            int color= queries[i][1];

            if(ballMap.find(ball) != ballMap.end()) {
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;
                if(colorMap[prevColor] == 0)
                    colorMap.erase(prevColor);
            }
            ballMap[ball] = color;
            colorMap[color]++;

            ans[i] = colorMap.size();
        }
        return ans;
    }


public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        return twoMaps(limit, queries, n);
       
        return bruteForce(limit , queries, n);
    }
};