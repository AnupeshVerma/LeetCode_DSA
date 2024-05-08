class Solution {
private:
    vector<string> solve(vector<int>& score, int n)
    {
        unordered_map<int, int> indexMap;
        for(int i=0; i<n; i++)
            indexMap[score[i]] = i;
        
        sort(score.begin(), score.end(), greater<int>());
        
        vector<string>ans(n);
        if(n>=1) ans[indexMap[score[0]]] = "Gold Medal";
        if(n>=2) ans[indexMap[score[1]]] = "Silver Medal";
        if(n>=3) ans[indexMap[score[2]]] = "Bronze Medal";
        
        for(int i=3; i<n; i++)
            ans[indexMap[score[i]]] = to_string(i+1);
        
        return ans;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        
        return solve(score, n);
    }
};