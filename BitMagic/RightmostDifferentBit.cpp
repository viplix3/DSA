// https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends


//User function Template for C++

/*  Function to find the first position with different bits
*   This function returns the position with different bit
*/
int posOfRightMostDiffBit(int m, int n)
{
    
    if(m==n)
        return -1;
    
    int mXORn = m^n;
    int diffBit = 0;
    
    while((mXORn & (1 << diffBit)) == 0)
        diffBit++;
    
    return diffBit+1;
    
    
}

// { Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         cout << posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}   // } Driver Code Ends