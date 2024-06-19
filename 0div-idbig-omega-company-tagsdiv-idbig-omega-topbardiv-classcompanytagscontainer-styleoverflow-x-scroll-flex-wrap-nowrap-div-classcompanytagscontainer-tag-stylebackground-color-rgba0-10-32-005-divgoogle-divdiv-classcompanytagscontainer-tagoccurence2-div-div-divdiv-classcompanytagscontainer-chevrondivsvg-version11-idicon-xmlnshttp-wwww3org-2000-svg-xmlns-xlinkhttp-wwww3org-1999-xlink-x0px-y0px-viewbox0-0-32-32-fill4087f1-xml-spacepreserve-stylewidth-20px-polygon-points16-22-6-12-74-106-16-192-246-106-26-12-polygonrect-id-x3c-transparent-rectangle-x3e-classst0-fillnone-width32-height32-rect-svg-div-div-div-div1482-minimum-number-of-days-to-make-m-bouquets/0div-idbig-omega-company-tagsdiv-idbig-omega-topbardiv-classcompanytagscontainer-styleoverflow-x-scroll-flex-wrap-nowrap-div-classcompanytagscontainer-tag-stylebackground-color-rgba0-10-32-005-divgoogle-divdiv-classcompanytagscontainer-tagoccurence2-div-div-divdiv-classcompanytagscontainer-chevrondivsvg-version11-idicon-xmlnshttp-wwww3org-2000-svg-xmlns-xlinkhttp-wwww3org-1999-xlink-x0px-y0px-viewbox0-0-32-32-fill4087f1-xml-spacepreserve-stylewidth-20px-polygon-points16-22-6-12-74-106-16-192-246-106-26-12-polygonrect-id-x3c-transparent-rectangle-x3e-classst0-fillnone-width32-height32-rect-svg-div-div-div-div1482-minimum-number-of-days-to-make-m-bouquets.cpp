class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int NoofB = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
            } else {
                NoofB += (count / k);
                count = 0;
            }
        }
        NoofB += (count / k);
        return NoofB >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m * k;
        if(val > bloomDay.size()) {
            return -1;
        }
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};