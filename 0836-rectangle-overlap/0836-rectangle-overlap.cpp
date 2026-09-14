class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec2 in reference of rec1
        bool top    = rec1[3] <= rec2[1];
        bool bottom = rec1[1] >= rec2[3];

        bool left  = rec1[0] >= rec2[2];
        bool right = rec1[2] <= rec2[0];

        return !(top || bottom || left || right);
    }
};