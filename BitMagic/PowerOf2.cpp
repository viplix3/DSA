// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1/

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Function to check power of two
bool isPowerofTwo(long long n){
    // If a number is power of 2, only 1 bit would be set in its binary representation. Checking for single set bit.
    return !(n & (n-1));
    
}

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;
        if(n<=0) // if n is less than equal to zero then it can't be a power of 2
        {
            cout<<"NO"<<endl; //so we print No
            continue; //continue and check for other values
        }

         if(isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}
  // } Driver Code Ends