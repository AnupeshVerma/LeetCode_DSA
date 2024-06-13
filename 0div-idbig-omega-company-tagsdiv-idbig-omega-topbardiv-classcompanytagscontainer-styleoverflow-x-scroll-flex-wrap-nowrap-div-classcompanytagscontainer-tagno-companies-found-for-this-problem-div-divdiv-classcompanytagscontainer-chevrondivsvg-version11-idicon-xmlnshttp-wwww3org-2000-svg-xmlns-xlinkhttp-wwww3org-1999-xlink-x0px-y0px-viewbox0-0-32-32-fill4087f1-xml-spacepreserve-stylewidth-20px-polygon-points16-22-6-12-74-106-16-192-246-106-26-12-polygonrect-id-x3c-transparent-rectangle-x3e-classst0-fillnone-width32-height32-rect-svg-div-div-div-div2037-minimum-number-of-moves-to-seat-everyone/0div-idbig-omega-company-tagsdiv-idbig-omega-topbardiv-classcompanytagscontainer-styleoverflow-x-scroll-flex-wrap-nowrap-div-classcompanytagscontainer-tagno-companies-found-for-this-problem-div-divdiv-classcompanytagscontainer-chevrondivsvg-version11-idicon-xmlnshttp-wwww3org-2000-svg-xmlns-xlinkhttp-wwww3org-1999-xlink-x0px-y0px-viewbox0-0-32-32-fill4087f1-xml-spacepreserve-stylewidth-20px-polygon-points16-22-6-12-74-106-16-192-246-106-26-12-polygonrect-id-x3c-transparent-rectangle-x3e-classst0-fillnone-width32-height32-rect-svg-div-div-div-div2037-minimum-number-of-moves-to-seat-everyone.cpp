class Solution {
private:
    int bruteForce(vector<int>& seats, vector<int>& students, int n)
    {
        int moves = 0;
        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        for(int i=0; i<n; i++)
        {
            moves += abs(students[i] - seats[i]);
        }
        
        return moves;
    }
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        int n = seats.size();
        
        return bruteForce(seats, students, n);
    }
};