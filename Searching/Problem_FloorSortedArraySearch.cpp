// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1/
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        
        int beginIdx = 0, endIdx = n-1;
        int candidateSol = -1;
        while(beginIdx <= endIdx){
            int midIdx = (beginIdx + endIdx) / 2.0;
            
            if(arr[midIdx] <= x){
                if((candidateSol == -1) || (arr[candidateSol] < arr[midIdx]))
                    candidateSol = midIdx;
                beginIdx = midIdx+1;
            }
            else
                endIdx = midIdx-1;
        }
        return candidateSol;
        
    }
};

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}

/*
Test Input
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19
Test Output
-1
1
3
*/