// https://leetcode.com/problems/reverse-pairs/

// Completely merge sort base easy to understand solution taken from discuss
class Solution {
    bool debug = false;
private:
    int merge(vector<int>& nums, int beginIdx, int midIdx, int endIdx) {
        if(debug) {
            cout << "LeftArr: ";
            for(int i = beginIdx; i <= midIdx; i++)
                cout << nums[i] << " ";
            cout << "\n";

            cout << "RightArr: ";
            for(int i = midIdx + 1; i <= endIdx; i++)
                cout << nums[i] << " ";
            cout << "\n";
        }
        
        
        int leftArrItr = beginIdx, rightArrItr = midIdx+1, sortedArrItr = 0;
        int inversionCheckItr = rightArrItr, numReversePairs = 0, count = 0;
        vector<int> sortedArr(endIdx - beginIdx + 1);
        
        while(leftArrItr <= midIdx) {
            // Checking inversions for current left array element with all the
            // right array elements, for next left array element, we will continue
            // at the index last left element was not > 2x right element
            // Hence the count will be added to total count 
            while(inversionCheckItr <= endIdx
                  && nums[leftArrItr] > 2L * nums[inversionCheckItr])
                count++, inversionCheckItr++;
            numReversePairs += count;
            
            // Sorting, copying all the right array elements less than current
            // left array element to sorted array
            while(rightArrItr <= endIdx && nums[rightArrItr] <= nums[leftArrItr])
                sortedArr[sortedArrItr++] = nums[rightArrItr++];
            
            // All the right array elements smaller than current left array element
            // have been copied to sorted array, now we can copy the current left
            // element to sorted array
            sortedArr[sortedArrItr++] = nums[leftArrItr++];
        }
        
        while(rightArrItr <= endIdx)
            sortedArr[sortedArrItr++] = nums[rightArrItr++];
        
        for(int i = 0; i < sortedArrItr; i++)
            nums[beginIdx + i] = sortedArr[i];
        
        if(debug)
            cout << "Num inversions counted: " << numReversePairs << "\n";
        
        return numReversePairs;
    }
    
    int countReversePairs(vector<int>& nums, int beginIdx, int endIdx) {
        int numReversePairs = 0;
        if(beginIdx < endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            numReversePairs += countReversePairs(nums, beginIdx, midIdx);
            numReversePairs += countReversePairs(nums, midIdx + 1, endIdx);
            numReversePairs += merge(nums, beginIdx, midIdx, endIdx);
        }
        
        if(debug) {
            cout << "Nums: ";
            for(int i = beginIdx; i <= endIdx; i++)
                cout << nums[i] << " ";
            cout << "\n\n";
        }
        
        return numReversePairs;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return countReversePairs(nums, 0, nums.size() - 1);
    }
};


// This has been taken from discuss
class Solution {
private:
    int merge(vector<int>& nums, int beginIdx, int midIdx, int endIdx) {
        int leftArrItr = beginIdx, rightArrItr = midIdx + 1;
        int numReversePairs = 0;
        
        while(leftArrItr <= midIdx && rightArrItr <= endIdx) {
            if(nums[leftArrItr] > 2L * nums[rightArrItr]) {
                numReversePairs += (midIdx - leftArrItr + 1);
                rightArrItr++;
            }
            else
                leftArrItr++;
        }
        
        sort(nums.begin() + beginIdx, nums.begin() + endIdx + 1);
        return numReversePairs;
    }
    
    int countReversePairs(vector<int>& nums, int beginIdx, int endIdx) {
        int numReversePairs = 0;
        if(beginIdx < endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            numReversePairs += countReversePairs(nums, beginIdx, midIdx);
            numReversePairs += countReversePairs(nums, midIdx + 1, endIdx);
            numReversePairs += merge(nums, beginIdx, midIdx, endIdx);
        }
        
        return numReversePairs;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return countReversePairs(nums, 0, nums.size() - 1);
    }
};

// Gives TLE, because of the while loop inside of merge while loop for counting inversions
class Solution {
    bool debug = false;
private:
    int merge(vector<int>& nums, int beginIdx, int midIdx, int endIdx) {
        int numElemsLeftArr = midIdx - beginIdx + 1;
        int numElemsRightArr = endIdx - midIdx;
        
        vector<int> leftArr(numElemsLeftArr), rightArr(numElemsRightArr);
        
        for(int i = 0; i < numElemsLeftArr; i++)
            leftArr[i] = nums[beginIdx + i];
        
        for(int j = 0; j < numElemsRightArr; j++)
            rightArr[j] = nums[midIdx + j + 1];
        
        
        if(debug) {
            cout << "LeftArr: ";
            for(int i = 0; i < numElemsLeftArr; i++)
                cout << leftArr[i] << " ";
            cout << "\n";

            cout << "RightArr: ";
            for(int i = 0; i < numElemsRightArr; i++)
                cout << rightArr[i] << " ";
            cout << "\n";
        }
        
        
        int leftArrItr = 0, rightArrItr = 0, sortedArrItr = beginIdx;
        int numReversePairs = 0;
        
        while(leftArrItr < numElemsLeftArr && rightArrItr < numElemsRightArr) {
            if(leftArr[leftArrItr] < rightArr[rightArrItr])
                nums[sortedArrItr++] = leftArr[leftArrItr++];
            else {
                
                int i = 0;
                while(leftArrItr + i < numElemsLeftArr) {
                    if(leftArr[leftArrItr + i] > 2L * rightArr[rightArrItr]) {
                        
                        if(debug)
                            cout << "Increasing inversion count by 1\n";
                            
                        numReversePairs++;
                    }
                    i++;
                }
                
                nums[sortedArrItr++] = rightArr[rightArrItr++];
            }
        }
        
        while(leftArrItr < numElemsLeftArr)
            nums[sortedArrItr++] = leftArr[leftArrItr++];
        
        while(rightArrItr < numElemsRightArr)
            nums[sortedArrItr++] = rightArr[rightArrItr++];
        
        return numReversePairs;
    }
    
    int countReversePairs(vector<int>& nums, int beginIdx, int endIdx) {
        int numReversePairs = 0;
        if(beginIdx < endIdx) {
            int midIdx = beginIdx + (endIdx - beginIdx) / 2;
            numReversePairs += countReversePairs(nums, beginIdx, midIdx);
            numReversePairs += countReversePairs(nums, midIdx + 1, endIdx);
            numReversePairs += merge(nums, beginIdx, midIdx, endIdx);
        }
        
        if(debug) {
            cout << "Nums: ";
            for(int i = beginIdx; i <= endIdx; i++)
                cout << nums[i] << " ";
            cout << "\n\n";
        }
        
        return numReversePairs;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return countReversePairs(nums, 0, nums.size() - 1);
    }
};