#include<bits/stdc++.h>
using namespace std;

void generateAndPrintSubsets(string setString, string currentSubset="", int numSubsetsParsed=0)
{
    if(numSubsetsParsed == setString.length())
    {
        cout<<currentSubset<<"\t";
        return;
    }

    generateAndPrintSubsets(setString, currentSubset, numSubsetsParsed+1);
    generateAndPrintSubsets(setString, currentSubset+setString[numSubsetsParsed], numSubsetsParsed+1);
}

int main(){
    string setString;
    while(true){
        printf("\n\nEnter string for generating all the subsets: ");
        cin>>setString;
        printf("All the subsets of the provided string are: \n");
        generateAndPrintSubsets(setString);

    }
    return 0;
}