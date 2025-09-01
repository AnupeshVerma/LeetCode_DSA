class Solution {
private:
    double priorityQueue(vector<vector<int>>& classes, int extraStudents, int n) {
        // Lambda to calculate the gain in pass ratio
        auto calculateGain = [](int pass, int total) {
            double pass_ratio = (double)pass / total;
            double new_pass_ratio = (double)(pass + 1) / (total + 1);

            return new_pass_ratio - pass_ratio;
        };

        priority_queue<pair<double, int>> pq;
        // Initialize the priority queue with initial gains for each class
        for (int i = 0; i < n; i++) {
            double gain_in_pass_ratio = calculateGain(classes[i][0], classes[i][1]);
            pq.push({gain_in_pass_ratio, i});
        }

        while(extraStudents--) {
            auto [gain, index] = pq.top();
            pq.pop();

            classes[index][0]++;
            classes[index][1]++;

            double gain_in_pass_ratio = calculateGain(classes[index][0], classes[index][1]);
            pq.push({gain_in_pass_ratio, index});
        }
        double pass_ratio_sum = 0;
        for(auto cls : classes)
            pass_ratio_sum += (double)cls[0] / cls[1];
        
        return pass_ratio_sum / n;
    }


public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        return priorityQueue(classes, extraStudents, n);
    }
};