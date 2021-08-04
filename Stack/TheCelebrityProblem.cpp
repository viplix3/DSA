// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int num_persons) 
    {
        stack<int> partyAnimals; // Will be using this to find connections
        
        for(int i=0; i<num_persons; i++)
            partyAnimals.push(i);
            
        while(partyAnimals.size() >= 2) {
            // Will check for 2 persons in each iteration and will reduce the stack
            // size by 1, hence, this is O(N) loop
            int person1 = partyAnimals.top();
            partyAnimals.pop();
            
            int person2 = partyAnimals.top();
            partyAnimals.pop();
            
            // If person 1 doesn't know person 2, person 1 is a candidate for celebrity
            if(M[person1][person2] == 0)
                partyAnimals.push(person1);
            else
                partyAnimals.push(person2);
        }
        
        // All person pair knowing each other would have eliminated one another in above loop
        // Hence, person at top of stack is a candidate for celebrity
        int celeb_candidate = partyAnimals.top();
        
        // We still need to check if this candidate is known by all the others, only then this can be a celebrity
        for(int i=0; i<num_persons; i++) {
            if(i != celeb_candidate) {
                // If there is any person who doesn't know celebrity candidate or if celebrity candidate knows any
                // other person, we won't be having any celebrity in the party
                if(M[i][celeb_candidate] == 0 || M[celeb_candidate][i] == 1)
                    return -1;
            }
        }
        
        return celeb_candidate;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends