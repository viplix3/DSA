// https://practice.geeksforgeeks.org/problems/merge-three-sorted-arrays-1587115620/1/

#include<bits/stdc++.h>
using namespace std; 


void printVector(const vector<int>& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

// The expected way of doing 3 way merge
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    { 
        int numElemsArr1 = arr1.size(), numElemsArr2 = arr2.size(), numElemsArr3 = arr3.size();
        vector<int> mergedArr(numElemsArr1 + numElemsArr2 + numElemsArr3);
        
        int arr1Itr = 0, arr2Itr = 0, arr3Itr = 0, mergedArrItr = 0;
        
        while(arr1Itr < numElemsArr1 || arr2Itr < numElemsArr2 || arr3Itr < numElemsArr3) {
            int arr1Val = (arr1Itr < numElemsArr1) ? arr1[arr1Itr] : INT_MAX;
            int arr2Val = (arr2Itr < numElemsArr2) ? arr2[arr2Itr] : INT_MAX;
            int arr3Val = (arr3Itr < numElemsArr3) ? arr3[arr3Itr] : INT_MAX;
            
            int minVal = min({arr1Val, arr2Val, arr3Val});
            
            if(arr1Itr < numElemsArr1 && arr1Val == minVal)
                mergedArr[mergedArrItr++] = arr1[arr1Itr++];
            else if(arr2Itr < numElemsArr2 && arr2Val == minVal)
                mergedArr[mergedArrItr++] = arr2[arr2Itr++];
            else
                mergedArr[mergedArrItr++] = arr3[arr3Itr++];
        }
        
        return mergedArr;
    } 

};

 // } Driver Code Ends
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeTwo(vector<int> &arr_1, vector<int> &arr_2)
    {
        vector<int> arr_3;
        int itr_1 = 0, itr_2 = 0;
        
        while(itr_1 < arr_1.size() && itr_2 < arr_2.size()){
            if(arr_1[itr_1] <= arr_2[itr_2]){
                arr_3.push_back(arr_1[itr_1]);
                itr_1++;
            }
            else{
                arr_3.push_back(arr_2[itr_2]);
                itr_2++;
            }
        }
        while(itr_1 < arr_1.size()){
            arr_3.push_back(arr_1[itr_1]);
            itr_1++;
        }
        while(itr_2 < arr_2.size()){
            arr_3.push_back(arr_2[itr_2]);
            itr_2++;
        }
        return arr_3;
    }
    
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        vector<int> merged_A_B = mergeTwo(A, B);
        vector<int> merged_A_B_C = mergeTwo(merged_A_B, C);
        return merged_A_B_C;
    } 

};

// { Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

    Solution obj;
    vector<int>ans = obj.mergeThree(A, B, C);
    for(auto i: ans)cout << i << " ";
    cout << "\n";
    // obj.printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 
  // } Driver Code Ends