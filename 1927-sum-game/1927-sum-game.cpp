class Solution {
public:
    bool sumGame(string num) {
        int n= num.size();
        int leftSum=0, rightSum=0;
        int qLeft=0, qRight=0;
        
        for(int i=0; i<n/2; i++)
        {
            if(num[i] == '?')
                qLeft++;
            else
                leftSum += num[i]-'0'; 
        }
        for(int i=n/2; i<n; i++)
        {
            if(num[i] == '?')
                qRight++;
            else
                rightSum += num[i]-'0'; 
        }
        
//         IF ALICE MAKE LEFT SIDE GREATER
        // No. of time Alice add 9 to left is equal to half of ? if no. of ? is even ans Half+1 if odd
        int newLeftSum = leftSum  + (qLeft/2 + qLeft%2)*9;
        // Now bob will try to maximize right side by adding 9
        // If qLeft is even, Alice have first chance in right else Bob try first
        /*
        qLeft=even AND qRight=even => Both have equal chances
        qLeft=even AND qRight=odd  => Alice have one more chance (Alice add 0)
        qLeft=odd  AND qRight=even => Both have equal chances
        qLeft=odd  AND qRight=odd  => Bob have an extra chance to add 9
        */
        int newRightSum = rightSum + qRight/2*9 + (qLeft%2 && qRight%2 ? 1:0)*9;
        if(newLeftSum > newRightSum)
            return true;
        
//         IF ALICE MAKE RIGHT SIDE GREATER
        newRightSum = rightSum + (qRight/2 + qRight%2)*9;
        newLeftSum  = leftSum + qLeft/2*9 + (qLeft%2 && qRight%2 ? 1 : 0)*9;
        if(newRightSum > newLeftSum)
            return true;
        
        return false;
    }
};