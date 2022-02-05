// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps4102/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int jumpSize[], int numSlots){
        if(numSlots <= 1) // No slot to jump to
            return 0;
        
        if(jumpSize[0] == 0)
            return -1;

        int numJumps = 1;
        int maxReach = jumpSize[0], numStepsLeft = jumpSize[0];

        for(int currSlot = 1; currSlot < numSlots; currSlot++) {
            if(currSlot == numSlots - 1) // We have reached the last slot
                return numJumps;
            
            maxReach = max(currSlot + jumpSize[currSlot], maxReach); // Max slot we can reach from current slot
            numStepsLeft -= 1; // We took one steps of the total steps allowed from current slot

            if(numStepsLeft == 0) {
                numJumps += 1; // As no more steps are left for current slot, we would have to jump

                if(currSlot >= maxReach) // If we are in a slot which is outside of our exploration range, we cannot reach end
                    return -1;
                numStepsLeft = maxReach - currSlot; // Otherwise, we reduce the steps by number of slots traversed
            }
        }

		return -1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}  // } Driver Code Ends