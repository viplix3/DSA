// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/


// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
private:
	static bool sortingComparator(Job J1, Job J2) {
		return (J1.profit > J2.profit);
	}
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
		int EMPTY = -1;
		sort(arr, arr+n, sortingComparator);

		int maxDeadline = arr[0].dead;
		for(int i=1; i<n; i++)
			maxDeadline = max(arr[i].dead, maxDeadline);

		int jobSlots[maxDeadline+1];
		fill(jobSlots, jobSlots + (maxDeadline+1), EMPTY);

		for(int i=0; i<n; i++) {
		    for(int j = min(maxDeadline+1, arr[i].dead)-1; j >= 0; j--)
		    	if(jobSlots[j] == EMPTY) {
				    jobSlots[j] = arr[i].profit;
				    break;
		    	}
		}


		int totalProfit = 0, numJobsDone = 0;
		for(int i=0; i<maxDeadline+1; i++)
			if(jobSlots[i] != EMPTY) {
				totalProfit += jobSlots[i];
				numJobsDone += 1;
			}

		return {numJobsDone, totalProfit};
    }
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends