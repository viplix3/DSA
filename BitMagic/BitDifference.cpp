// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1/

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    
    int aXORb = a^b; //Get all the different bits
    int bitsFlipped = 0;
    
    while(aXORb){
        bitsFlipped++;
        aXORb = aXORb & (aXORb-1); // Un-setting the last bit of XOR
    }
    
    return bitsFlipped;
    
}

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends