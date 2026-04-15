class Solution {
private:
    int min_dist = INT_MAX;
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        for(int i=0; i<n; i++) {
            int leftIndex  = (startIndex + i) % n;
            int rightIndex = (startIndex - i + n) % n;

            if(words[leftIndex] == target || words[rightIndex] == target)
                min_dist = min(min_dist, i);
            
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};