class Solution {
private:
    int bruteForce(vector<int>& tickets, int k, int n)
    {
        int time = 0;
        if(tickets[k] == 1)
            return k+1;
        
        while(tickets[k] != 0)
        {
            for(int j=0; j<n; j++)
            {
                if(tickets[j] > 0)
                    time++;
                tickets[j]--;
                if (j == k && tickets[j] == 0)  
                    return time;
            }
            
        }
        return time;
    }
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        
        
        return bruteForce(tickets, k, n);
    }
};