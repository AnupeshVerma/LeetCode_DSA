class Solution {
    public int bruteForce(String s, int n) {
        int count = 0;
        
        for(int i=0; i<n-1; i=i+2) {
            if(s.charAt(i) != s.charAt(i+1))
                count++;
        }
        return count;
    }
    public int minChanges(String s) {
        int n = s.length();
        
        return bruteForce(s, n);
    }
}