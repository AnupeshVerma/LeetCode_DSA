class Solution {
private:
    vector<string> greedy(vector<string>& w, vector<int>& g, int n) {
        vector<string> ans;

        ans.push_back(w[0]);

        for(int i=1; i<n; i++) {
            if(g[i] != g[i-1])
                ans.push_back(w[i]);
        }
        return ans;
    }
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        return greedy(words, groups, n);
    }
};