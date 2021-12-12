// https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/1/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int numDigits, int sum)
    {
        string currNum = "";
        int numDigitsFilled = 0, currSum = sum;
        
        while(numDigitsFilled != numDigits) {
            for(int currDigit = 9; currDigit >= 0; currDigit--) {
                if(currSum == 0) {
                    currNum += "0";
					numDigitsFilled += 1;
                    break;
                }
                if(currSum >= currDigit) {
                    currNum += to_string(currDigit);
                    currSum -= currDigit;
					numDigitsFilled += 1;
					break;
                }
            }
        }

        if(currSum != 0)
            return "-1";
        return currNum;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends