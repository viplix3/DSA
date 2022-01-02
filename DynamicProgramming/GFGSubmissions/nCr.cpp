// https://practice.geeksforgeeks.org/problems/ncr-1587115620/1/

// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{
private:
  static constexpr int MODULO_VAL = 1000000007;

public:
    //Function to return nCr mod 10^9+7 for given n and r. 
    int nCrModp(int n, int r) 
    {
      if(r > n)
        return 0;
      
      // As 4C3 == 4C1, we can simply compute 4C1 instead of 4C3 which would save some computation
      r = ((n - r) < r) ? (n-r) : r; 

      vector<int> binomialCoefficients(r + 1, 0);
      binomialCoefficients[0] = 1; // nC0 is always 1

      // Calculating PASCAL's triangle upto r numbers as nCr follows pascal's triangle
      // The nth lever of pascal's triangle will be holding value of nCr
      for(int currLevel = 1; currLevel <= n; currLevel++)
        for(int i = min(currLevel, r); i > 0; i--) {
          // Pascal's traingle n-th level values are adjacent values of (n-1)-th level, right to left
          // Each i-th iteration of outer loop, the values of binomialCoefficients array would be updated to
          // hold i-th level of pascal's triangle which can be directly used to get nCr value 
          binomialCoefficients[i] = (binomialCoefficients[i] + binomialCoefficients[i-1]) % MODULO_VAL;
        }

        return binomialCoefficients[r];
    } 
};

// { Driver Code Starts.
// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      Solution ob;
      //calling method nCrModp()
      cout << ob.nCrModp(n, r) << endl;
  }
  
  return 0; 
}
  // } Driver Code Ends