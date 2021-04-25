// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1/

//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

/*  function to find position of first set 
    bit in the given number
 * n: given input for which we want to get
      the position of first set bit
 */
unsigned int getFirstSetBit(int n){
    
    if(n==0)
        return 0;
    
    int lsb = 1;
    for(; n!=0; lsb++){
        if(n&1)
            return lsb;
        n = n >> 1;
    }
    
    
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        printf("%u\n", getFirstSetBit(n)); // function to get answer
    }
	return 0;
}
  // } Driver Code Ends