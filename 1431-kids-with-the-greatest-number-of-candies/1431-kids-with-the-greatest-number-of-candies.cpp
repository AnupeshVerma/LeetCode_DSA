class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxm = *max_element(candies.begin(), candies.end());
        
        for( auto i : candies)
        {
            if(i+extraCandies >= maxm)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
        
    }
};