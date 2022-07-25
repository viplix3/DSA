// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

// Check different bits, i.e. XOR and check set bits
class Solution {
private:
    int countSetBits(int binaryNumber) {
        int numSetBits = 0;
            
        while(binaryNumber) {
            binaryNumber = binaryNumber & (binaryNumber - 1);
            numSetBits++;
        }
        
        return numSetBits;
    }
    
public:
    int minBitFlips(int start, int goal) {
        return countSetBits(start ^ goal);
    }
};