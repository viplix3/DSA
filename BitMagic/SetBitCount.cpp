// https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits


int countSetBits(int N){ 
	int powerOfTwo = 2, totalSetBits = 0;
	int totalNums = N+1; // Taking care of 0
	
	while(powerOfTwo <= totalNums){
	    int numberOf01Pairs = totalNums / powerOfTwo;
	    int numberOf1InPair = powerOfTwo >> 1;
        int numOnesUnAccounted = 0;
	    
        // If number of pairs are odd then there might be some pairs which are unaccounted
        if (numberOf01Pairs % 2)
            numOnesUnAccounted = (totalNums) % powerOfTwo;

	    totalSetBits += (numberOf01Pairs * numberOf1InPair) + numOnesUnAccounted;
	    powerOfTwo = powerOfTwo << 1;
	}
	
	return totalSetBits;
}


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends