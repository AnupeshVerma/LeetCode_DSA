class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        
        int curr = first;
        for(auto it:encoded)
        {
            int next = it^curr;
            curr = next;
            ans.push_back(next);
        }
        return ans;
    }
};