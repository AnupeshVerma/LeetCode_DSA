class Solution {
private:
    int bruteForce(vector<int>& tickets, int k, int n)
    {
        int time = 0;
        
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
    
    int onePass(vector<int>& tickets, int k, int n)
    {
        int time = 0;
        
        for(int i=0; i<n; i++)
        {
            if(i<=k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k]-1, tickets[i]);
        }
        return time;
            
    }
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets[k] == 1)
            return k+1;
        
        int n = tickets.size();
        
        // return bruteForce(tickets, k, n);
        
        return onePass(tickets, k, n);
    }
};