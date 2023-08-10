class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero=0, one=0, n = students.size();
        
        for(int i:students)
            if(i)
                one++;
            else
                zero++;
        
        for(int j=0; j<n; j++)
        {
            if(sandwiches[j])
                one--;
            else
                zero--;
            if(one<0 || zero<0)
                return n-j;
        }
        return 0;
    }
};