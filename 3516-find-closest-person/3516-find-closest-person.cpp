class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distxz = abs(z - x);
        int distyz = abs(z - y);

        return distxz == distyz ? 0 : (distxz > distyz ? 2 : 1);
    }
};