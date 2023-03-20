class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int size = fb.size(), vacant=0;
        if(size==1 && fb[0]==0)
            return true;
      
        if(fb[0]==0 && fb[1]==0)
        {
            fb[0]=1;
            vacant++;
        }
        for(int i=1; i<size-1; i++)
        {
            if(fb[i-1]==0 && fb[i]==0 && fb[i+1]==0)
            {
                vacant++;
                fb[i] = 1;
            }
        }
        if(fb[size-1]==0 && fb[size-2]==0)
            vacant++;
        if(vacant >= n)
            return true;
        else 
            return false;
    }
};