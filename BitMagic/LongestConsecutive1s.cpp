// https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1/

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

/*  Function to calculate the largest consecutive ones
*   x: given input to calculate the largest consecutive ones
*/
int maxConsecutiveOnes(int x)
{
 
    int count = 0;
    while(x){
        count++;
        x = x & (x>>1); // Remove one of the consecutive 1s
    }
    
    return count;
}



// { Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		
		//calling maxConsecutiveOnes() function
		cout<<maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends