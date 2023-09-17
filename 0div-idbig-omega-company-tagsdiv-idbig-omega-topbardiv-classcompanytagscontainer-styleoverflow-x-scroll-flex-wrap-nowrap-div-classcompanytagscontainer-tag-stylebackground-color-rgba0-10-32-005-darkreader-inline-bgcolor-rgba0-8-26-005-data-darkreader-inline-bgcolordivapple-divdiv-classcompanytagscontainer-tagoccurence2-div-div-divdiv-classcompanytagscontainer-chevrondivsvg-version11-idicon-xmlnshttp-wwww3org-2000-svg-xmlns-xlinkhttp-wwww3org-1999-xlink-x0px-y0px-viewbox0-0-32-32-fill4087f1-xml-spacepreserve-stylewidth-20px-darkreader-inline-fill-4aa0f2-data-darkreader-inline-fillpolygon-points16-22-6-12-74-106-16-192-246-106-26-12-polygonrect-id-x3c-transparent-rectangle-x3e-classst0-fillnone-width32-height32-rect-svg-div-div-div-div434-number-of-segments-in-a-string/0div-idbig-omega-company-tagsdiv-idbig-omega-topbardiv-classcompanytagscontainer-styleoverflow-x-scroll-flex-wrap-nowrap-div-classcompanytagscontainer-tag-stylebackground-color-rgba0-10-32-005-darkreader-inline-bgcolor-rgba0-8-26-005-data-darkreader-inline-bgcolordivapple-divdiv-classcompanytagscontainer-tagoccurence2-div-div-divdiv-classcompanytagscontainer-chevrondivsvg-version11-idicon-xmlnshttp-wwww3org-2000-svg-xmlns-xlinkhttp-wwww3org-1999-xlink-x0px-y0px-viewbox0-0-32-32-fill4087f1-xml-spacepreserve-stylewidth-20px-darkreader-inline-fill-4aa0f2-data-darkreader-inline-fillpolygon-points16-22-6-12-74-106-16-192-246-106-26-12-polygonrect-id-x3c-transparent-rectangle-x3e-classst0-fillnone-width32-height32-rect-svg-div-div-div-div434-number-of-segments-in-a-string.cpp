class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        bool space = true;
        
        for(auto it : s)
        {
            if(it != ' ' && space ==true)
            {
                segments++;
                space = false;
            }
            else if(it == ' ')
                space = true;
        }
        return segments;
    }
    
};