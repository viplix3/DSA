// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
private:
	void buildLargestNumber(string inNum, string& outNum, int numSwaps, int currIdx) {
		int numDigits = inNum.length();

		if(numSwaps == 0 || currIdx == numDigits)
			return;

		int currDigit = inNum[currIdx] - '0';
		int swapIdx = currIdx;

		for(int i = currIdx+1; i < numDigits; i++)
			if(currDigit < inNum[i] - '0') {
				currDigit = inNum[i] - '0';
				swapIdx = i;
			}
		
		if(swapIdx != currIdx)
			numSwaps -= 1;
		
		for(int i = numDigits; i >= currIdx; i--) {
			// swapping and max-checking would be done for all the occurences of digits to be swapped
			if(inNum[i] - '0' == currDigit) {
				swap(inNum[currIdx], inNum[i]);
				outNum = max(inNum, outNum);
				buildLargestNumber(inNum, outNum, numSwaps, currIdx+1);
				swap(inNum[currIdx], inNum[i]);
			}
		}
	}

public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
		string largestNum = str;
		buildLargestNumber(str, largestNum, k, 0);
		return largestNum;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends