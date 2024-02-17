class Solution {
private:
    int solve(vector<int>&h, int b, int l)
    {
        int n=h.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<n-1; i++)
        {
            int diff = h[i+1]-h[i];
            if(diff > 0)
            {
                pq.push(diff);
                if(pq.size() > l)
                {
                    b -= pq.top();
                    pq.pop();
                }
                if(b < 0)
                return i;
            }
            
        }
         return n-1;
    }
public:
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
  
       
        return solve(heights, bricks, ladders);
    }
};