class Solution {
private:
    int solve(vector<vector<int>>& intervals) {
        vector<int> start, end;
        
        for(auto vec : intervals) {
            start.push_back(vec[0]);
            end.push_back(vec[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int end_index = 0, group_count = 0;
        for(int s : start)
            if(s > end[end_index])
               end_index ++;
              else
               group_count ++;
        
        return group_count;
    }
public:
    int minGroups(vector<vector<int>>& intervals) {
          
        return solve(intervals);
    }
};
