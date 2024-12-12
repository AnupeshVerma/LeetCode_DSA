class Solution {
    long long usingSorting(vector<int>& gifts, int k, int n) {
        long long ans = 0;

        for(int i=0; i<k; i++) {
            sort(gifts.begin(), gifts.end());
            gifts[n-1] = floor(sqrt(gifts[n-1]));
        }
        for(auto num : gifts)
            ans += num;
        return ans;
    }
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        return usingSorting(gifts, k, n);
    }
};