// Difficuly is solving the problem in O(1) extrac space.

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
void frequencycount(vector<int>& arr,int n);

 // } Driver Code Ends


void frequencycount(vector<int>& arr,int n)
{ 
    // Initially:    [2, 3,  2,  3, 5]
    // After step 1: [1, 2,  1,  2, 4]
    // After step 2: [1, 12, 11, 2, 9]
    // After step 3: [0, 2,  2,  0, 1]
    
    for(int i=0; i<n; i++) // Make every element range from [0, N)
        arr[i] -= 1;
    
    // Add N to count occurence of every element.
    for(int i=0; i<n; i++)
        arr[arr[i]%n] += n;
        
    // Devide each element in arr by n to get frequencies
    for(int i=0; i<n; i++)
        arr[i] /= n;
}


// { Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int n;
	    //size of array
	    cin >> n; 
	    
	    vector<int> arr(n,0);
	    
	    //adding elements to the vector
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; 
	    }

        //calling frequncycount() function
		frequencycount(arr,n); 
		
		//printing array elements
	    for (int i =0; i<n; i++) 
			cout<<arr[i]<<" ";
	    cout<<endl;
	}	
	return 0; 
}




  // } Driver Code Ends