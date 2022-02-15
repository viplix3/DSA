// 5
// 9 12 20 25 35 15 17 23 28 45 21 31 38 40 51 28 41 47 52 62 38 43 48 56 65
// 23

// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

struct Triplet {
    int data, rowIdx, colIdx;
    
    Triplet(int _data, int _rowIdx, int _colIdx)
        : data(_data), rowIdx(_rowIdx), colIdx(_colIdx)
    {}
};

struct TripletComparator {
    bool operator()(const Triplet& T1, const Triplet& T2) {
        return T1.data > T2.data;
    }
};

int kthSmallest(int matrix[MAX][MAX], int n, int k) {
    priority_queue<Triplet, vector<Triplet>, TripletComparator> TripletMinHeap;
    
    for(int i = 0;  i < n; i++)
        TripletMinHeap.push(Triplet(matrix[i][0], i, 0));
    
    Triplet currTriplet = TripletMinHeap.top(); 
    for(int i = 0; i < k; i++) {
        currTriplet = TripletMinHeap.top();
        TripletMinHeap.pop();
        
        if(currTriplet.colIdx + 1 < n)
            TripletMinHeap.push(Triplet(matrix[currTriplet.rowIdx][currTriplet.colIdx + 1],
                                    currTriplet.rowIdx, currTriplet.colIdx + 1));
    }
    
    return currTriplet.data;
}
