#define ll long long int
class Solution {
private:
    
    int solve(int n, vector<vector<int>>&meet)
    {
        sort(meet.begin(), meet.end());
        
        vector<int> record(n, 0);
        
        auto cmp=[](const pair<long long,int>&a, const pair<long long,int>&b)
        {   
            return a.first==b.first ? a.second>b.second : a.first>b.first;
        };
        priority_queue<int, vector<int>, greater<int>>freeRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp)>booked;  // <endTime, roomsId>
        
        
//         Initially all rooms are free
        for(int i=0; i<n; i++)
            freeRooms.push(i);
        
        for(auto &m:meet)
        {
            int newStart = m[0], newEnd = m[1];
            
//             Recover possible rooms before the next meeting's start time
            while(!booked.empty() && booked.top().first <= newStart)
            {
                freeRooms.push(booked.top().second);
                booked.pop();
            }
            
//             Start the meeting, if any room is free
            if(!freeRooms.empty())
            {
                int roomId = freeRooms.top();
                int endTime = newEnd;
                
                booked.push({endTime, roomId});
                freeRooms.pop();
                record[roomId]++;
            }
            
//             If no room is free, then start in which meeting end first
            else
            {
                int roomId = booked.top().second;
                long long endTime = booked.top().first + (newEnd-newStart);
                
                booked.pop();
                booked.push({endTime, roomId});
                record[roomId]++;
            }
            
        }
        int ans=0, maxCount=0;
        for(int i=0; i<n; i++)
        {
            cout<<record[i]<<" ";
            if(record[i] > maxCount)
            {
                maxCount = record[i];
                ans = i;
            }
        }
        return ans;
    }
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        return solve(n, meetings);
    }
};