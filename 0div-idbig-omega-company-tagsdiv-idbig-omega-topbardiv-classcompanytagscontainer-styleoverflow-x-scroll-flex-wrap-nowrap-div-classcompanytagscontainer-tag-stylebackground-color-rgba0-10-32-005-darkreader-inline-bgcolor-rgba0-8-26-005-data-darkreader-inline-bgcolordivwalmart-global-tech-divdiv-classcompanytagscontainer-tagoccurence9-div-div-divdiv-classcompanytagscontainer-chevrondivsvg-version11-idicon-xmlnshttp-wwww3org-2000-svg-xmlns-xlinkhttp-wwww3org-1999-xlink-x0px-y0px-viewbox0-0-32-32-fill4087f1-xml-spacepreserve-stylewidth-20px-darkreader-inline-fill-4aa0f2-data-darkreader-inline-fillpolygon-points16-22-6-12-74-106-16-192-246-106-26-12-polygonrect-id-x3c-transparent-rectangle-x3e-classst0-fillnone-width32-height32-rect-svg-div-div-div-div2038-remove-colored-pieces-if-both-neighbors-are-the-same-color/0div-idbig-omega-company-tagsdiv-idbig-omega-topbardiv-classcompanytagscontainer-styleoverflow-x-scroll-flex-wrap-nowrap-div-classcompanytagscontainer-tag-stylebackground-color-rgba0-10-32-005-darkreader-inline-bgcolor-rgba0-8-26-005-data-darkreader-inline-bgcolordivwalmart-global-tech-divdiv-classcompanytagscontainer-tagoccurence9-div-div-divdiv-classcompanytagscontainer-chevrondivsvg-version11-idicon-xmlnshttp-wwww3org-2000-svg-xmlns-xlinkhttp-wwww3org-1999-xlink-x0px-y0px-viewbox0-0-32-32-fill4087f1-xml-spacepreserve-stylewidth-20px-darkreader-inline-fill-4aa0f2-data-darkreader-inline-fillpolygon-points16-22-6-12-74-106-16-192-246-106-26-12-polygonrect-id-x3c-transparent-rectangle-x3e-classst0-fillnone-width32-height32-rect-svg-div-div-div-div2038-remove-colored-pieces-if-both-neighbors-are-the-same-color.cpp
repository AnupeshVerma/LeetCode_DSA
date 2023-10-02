class Solution {
public:
    bool winnerOfGame(string colors) {
        int AliceChance = 0;
        int BobChance = 0;
        
        for(int i=1; i<colors.size()-1; i++)
        {
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A')
                AliceChance++;
            if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B')
                BobChance++;
        }
        
        if(AliceChance > BobChance)
            return true;
        return false;
    }
};