class Solution {
private:
    int simulate(int n, int k)
    {
        vector<int> circle;
        for(int i=0; i<n; i++)
            circle.push_back(i+1);
        
        int startIndex  = 0;
        while(circle.size() > 1)
        {
            int removeIndex = (startIndex + k - 1)%circle.size();
            
            circle.erase(circle.begin() + removeIndex);
            
            startIndex = removeIndex;
        }
        return circle.front();
    }
public:
    int findTheWinner(int n, int k) {
        
        return simulate(n, k);
    }
};