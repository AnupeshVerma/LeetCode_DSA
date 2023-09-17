class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int>ans;
        
        sort(potions.begin(), potions.end());
        
        for(auto spell : spells)
        {
            long long minRequired = ceil(1.0*success/spell);
            cout<<minRequired<<"  ";
            int index = lower_bound(potions.begin(), potions.end(), minRequired) - potions.begin();
            cout<<index<<" ";
            ans.push_back(m-index);
        }
        return ans;
    }
};