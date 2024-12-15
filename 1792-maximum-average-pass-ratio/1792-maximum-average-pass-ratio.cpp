#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to store the maximum gain first
        auto gain = [](const pair<int, int>& cls) {
            int pass = cls.first, total = cls.second;
            return double(pass + 1) / (total + 1) - double(pass) / total;
        };

        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            pq.push({gain({pass, total}), {pass, total}});
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto [curr_gain, curr_class] = pq.top();
            pq.pop();

            int pass = curr_class.first, total = curr_class.second;

            // Add one student to the current class
            pass++, total++;
            pq.push({gain({pass, total}), {pass, total}});
        }

        // Calculate the final average pass ratio
        double total_ratio = 0;
        while (!pq.empty()) {
            auto [_, cls] = pq.top();
            pq.pop();
            total_ratio += double(cls.first) / cls.second;
        }

        return total_ratio / classes.size();
    }
};
