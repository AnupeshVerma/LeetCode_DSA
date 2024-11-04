class Solution {
    public String compressedString(String word) {
        int n = word.length();
        StringBuilder comp = new StringBuilder("");
        int i = 0;
        
        while(i<n) {
            int count = 0;
            char curr = word.charAt(i);
            
            while(i<n && count<9 && word.charAt(i) == curr) {
                count++;
                i++;
            }
            comp.append(count).append(curr);
        }
        return comp.toString();
    }
}