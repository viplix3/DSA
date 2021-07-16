// https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string-1587115621/1/

#include<iostream>
using namespace std;


class Solution
{
	public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	int sum = 0;
    	string curr_num;
    	
    	for(int i=0; i<str.length(); i++) {
			if('0' <= str[i] && str[i] <= '9')
				curr_num += str[i];
			else if(curr_num == "")
					continue;
			else {
				sum += stoi(curr_num);
				curr_num = "";
			}
    	}

		if(curr_num != "")
			sum += stoi(curr_num);
    	
    	return sum;
    	
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } D