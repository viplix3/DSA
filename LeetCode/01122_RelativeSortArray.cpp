// https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int numElemsArr1 = arr1.size(), numElemsArr2 = arr2.size();
        map<int, int> frequencyMap;
        
        for(int i = 0; i < numElemsArr1; i++)
            frequencyMap[arr1[i]]++;
        
        int arr1SortedIdx = 0;
        for(int i = 0; i < numElemsArr2; i++) {
            while(frequencyMap[arr2[i]] != 0) {
                arr1[arr1SortedIdx++] = arr2[i];
                frequencyMap[arr2[i]]--;
            }
        }
        
        for(auto remainingElem : frequencyMap)
            while(remainingElem.second > 0) {
                arr1[arr1SortedIdx++] = remainingElem.first;
                remainingElem.second--;
            }
        
        return arr1;
    }
};