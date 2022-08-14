// https://leetcode.com/problems/sort-colors/submissions/

// Hoare's partition based solution
class Solution {
public:
    void sortColors(vector<int>& colors) {
        constexpr int RED = 0, WHITE = 1, BLUE = 2;
        int redIdx = 0, whiteIdx = 0, blueIdx = colors.size() - 1;
        
        while(whiteIdx <= blueIdx) {
            // Everything between 0 and redIdx should be RED
            if(colors[whiteIdx] == RED) {
                swap(colors[redIdx], colors[whiteIdx]);
                redIdx++, whiteIdx++;
            }
            // Everything bwetween redIdx and whiteIdx should be WHITE
            else if(colors[whiteIdx] == WHITE) {
                whiteIdx++;
            }
            // Everything bwetween blueIdx to the end of array should be blue
            else if(colors[whiteIdx] == BLUE) {
                swap(colors[whiteIdx], colors[blueIdx]);
                blueIdx--;
            }
        }
    }
};