// https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-BitMagic/problem/maximum-and-value-1587115620
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int patternMatches(int pattern, int arr[], int N)
    {
        int matchCount = 0;

        for (int i = 0; i < N; i++)
            if ((pattern & arr[i]) == pattern)
                matchCount++;

        return matchCount;
    }

public:
    int maxAND(int arr[], int N)
    {
        int maxANDValue = 0;

        for (int bit = 31; bit >= 0; bit--)
        {
            // If we right shift 1 by bit number of times (starting with MSB at position 31)
            // we check if atleast 2 number from the array has that bit set, if yes, our
            // maximum AND value would have that bit as set.
            // We'll update out pattern with that bit set and continue finding more set bits
            // moving from MSB to LSB
            if (patternMatches(maxANDValue | (1 << bit), arr, N) >= 2)
                maxANDValue = maxANDValue | (1 << bit);
        }

        return maxANDValue;
    }
};