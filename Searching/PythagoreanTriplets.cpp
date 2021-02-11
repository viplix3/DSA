#include<bits/stdc++.h>
using namespace std;

vector<int> findPair(vector<int> &arr, int beginIdx, int endIdx, int requiredSquaredSum)
{
    vector<int> requiredSumPairs;
    while(beginIdx <= endIdx){
        int squaredSum = (arr[beginIdx]*arr[beginIdx]) + (arr[endIdx]*arr[endIdx]);
        if(squaredSum == requiredSquaredSum){
            requiredSumPairs.push_back(arr[beginIdx]);
            requiredSumPairs.push_back(arr[endIdx]);
            beginIdx += 1;
        }
        else if(squaredSum < requiredSquaredSum)
                beginIdx += 1;
        else
            endIdx -= 1;
    }
    return requiredSumPairs;
}

vector<vector <int>> findPythagorenTriplets(vector<int> &arr)
{
    vector<vector <int>> pythagoreanTriplets;
    int requiredPairSquaredSum; 

    for(int i=0; i<arr.size()-1; i++){
        requiredPairSquaredSum = arr[arr.size()-(i+1)]*arr[arr.size()-(i+1)];
        vector<int> sumPairs = findPair(arr, 0, arr.size()-(i+1), requiredPairSquaredSum);

        if(sumPairs.size() != 0){
            vector<int> triplet;
            for(int j=0; j<sumPairs.size()-1; j+=2){
                triplet.push_back(sumPairs[j]);
                triplet.push_back(sumPairs[j+1]);
                triplet.push_back(arr[arr.size()-(i+1)]);
                pythagoreanTriplets.push_back(triplet);
            }
        }
    }
    return pythagoreanTriplets;
}

void print2DArray(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void printArray(vector<int> arr)
{
    for(int i=0; i<arr.size(); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    vector<int> test_array_1 = {2, 3, 4, 5, 6};
    vector<int> test_array_2 = {4, 5, 6, 10, 12};
    vector<int> test_array_3 = {3, 8, 5};
    vector<int> test_array_4 = {42 ,12 ,54 ,69 ,48 ,45 ,63 ,58 ,38 ,60 ,24 ,42 ,30 ,79 ,17 ,36 ,91 ,43 ,89 
                                ,7 ,41 ,43 ,65 ,49 ,47 ,6 ,91 ,30 ,71 ,51 ,7 ,2 ,94 ,49 ,30 ,24 ,85 ,55 ,57 ,41 
                                ,67 ,77 ,32 ,9 ,45 ,40 ,27 ,24 ,38 ,39 ,19 ,83 ,30 ,42 ,34 ,16 ,40 ,59 ,5 ,31 ,78};
    vector<vector <int>> pythagoreanTriplets;

    printf("\nContents of the input array: ");
    printArray(test_array_1);
    pythagoreanTriplets = findPythagorenTriplets(test_array_1);
    if(pythagoreanTriplets.size() == 0)
        printf("No pythagorean triplets present in the provided input array\n");
    else{
        printf("Pythagorean triplets in the given array are: \n");
        print2DArray(pythagoreanTriplets);
    }

    printf("\nContents of the input array: ");
    printArray(test_array_2);
    pythagoreanTriplets = findPythagorenTriplets(test_array_2);
    if(pythagoreanTriplets.size() == 0)
        printf("No pythagorean triplets present in the provided input array\n");
    else{
        printf("Pythagorean triplets in the given array are: \n");
        print2DArray(pythagoreanTriplets);
    }

    printf("\nContents of the input array: ");
    printArray(test_array_3);
    pythagoreanTriplets = findPythagorenTriplets(test_array_3);
    if(pythagoreanTriplets.size() == 0)
        printf("No pythagorean triplets present in the provided input array\n");
    else{
        printf("Pythagorean triplets in the given array are: \n");
        print2DArray(pythagoreanTriplets);
    }

    printf("\nContents of the input array: ");
    sort(test_array_4.begin(), test_array_4.end());
    printArray(test_array_4);
    pythagoreanTriplets = findPythagorenTriplets(test_array_4);
    if(pythagoreanTriplets.size() == 0)
        printf("No pythagorean triplets present in the provided input array\n");
    else{
        printf("Pythagorean triplets in the given array are: \n");
        print2DArray(pythagoreanTriplets);
    }
    return 0;
}