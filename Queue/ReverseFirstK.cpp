// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> K_rev_stack;
	queue<int> qrev;

    while(k--) {
        K_rev_stack.push(q.front());
        q.pop();
    }

	while(q.empty() == false) {
		qrev.push(q.front());
		q.pop();
	}
    
    while(K_rev_stack.empty() == false) {
        q.push(K_rev_stack.top());
        K_rev_stack.pop();
    }
    
	while(qrev.empty() == false) {
		q.push(qrev.front());
		qrev.pop();
	}
    
    return q;
}