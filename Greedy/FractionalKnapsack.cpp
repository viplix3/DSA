// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
private:
    static bool selectionComparator(Item data1, Item data2) {
    	double value1 = data1.value / (double)data1.weight;
    	double value2 = data2.value / (double)data2.weight;
    
    	return (value1 > value2);
    }

public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int knapSack, Item weightValue[], int numItems)
    {
        sort(weightValue, weightValue+numItems, selectionComparator);

    	double numSelectedItems = 0;
    	for(int i=0; i<numItems; i++) {
    		if(knapSack > weightValue[i].weight) {
    			numSelectedItems += weightValue[i].value;
    			knapSack -= weightValue[i].weight;
    		}
    		else if(0 < knapSack && knapSack <= weightValue[i].weight) {
    		    double selection_ratio = knapSack / (double)weightValue[i].weight;
    			numSelectedItems +=  selection_ratio * weightValue[i].value;
    			break;
    		}
    		if(knapSack == 0)
    			break;
    	}
    
    	return numSelectedItems;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends