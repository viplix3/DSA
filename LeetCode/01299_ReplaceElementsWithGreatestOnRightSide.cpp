// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int currMax = -1, numElems = arr.size();
        
        for(int i = numElems - 1; i >= 0; i--) {
            int currElem = arr[i];
            arr[i] = currMax;
            
            if(currElem > currMax)
                currMax = currElem;
        }
        
        return arr;
    }
};