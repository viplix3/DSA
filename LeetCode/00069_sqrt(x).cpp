// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int lowerBound = 1, upperBound = x;
        int potentialSqrt;
        
        while(lowerBound <= upperBound) {
            int sqrtCandidate = lowerBound + (upperBound - lowerBound) / 2;
            
            if(sqrtCandidate == (x / sqrtCandidate)) {
                return sqrtCandidate;
            }
            else if(sqrtCandidate > (x / sqrtCandidate))
                upperBound = sqrtCandidate - 1;
            else {
                lowerBound = sqrtCandidate + 1;
                potentialSqrt = sqrtCandidate; // If cannot find a closer match
            }
        }
        
        return potentialSqrt;
    }
};