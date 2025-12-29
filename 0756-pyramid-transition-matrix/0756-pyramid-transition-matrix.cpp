class Solution {
private:
    unordered_map<string, bool> memo;

    bool solve(string curr, string above, int idx, unordered_map<string, vector<char>> &mp) {
        if(curr.size() == 1) // We're on top
            return true;

        string key = curr + "_" + to_string(idx) + "_" + above;
        if(memo.count(key))
            return memo[key];

        if(idx == curr.size()-1) { // Move to next or above layer
            return memo[key] = solve(above, "", 0, mp);
        }

        string base_pair = curr.substr(idx, 2);
        if(mp.find(base_pair) == mp.end())
            return memo[key] = false;
        
        for(char top : mp[base_pair]) {
            above.push_back(top);
            if(solve(curr, above, idx+1, mp) == true)
                return memo[key] = true;
            above.pop_back();
        }

        return memo[key] = false;
    }


public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        // Populate the allowed into the map
        for(string pair : allowed) {
            mp[pair.substr(0, 2)].push_back(pair[2]);
        }

        return solve(bottom, "", 0, mp);
    }
};