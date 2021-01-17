#include<bits/stdc++.h>
using namespace std;

void findAndPrintStringPermutations(string inputString, int currentFixedCharacterIdx=0)
{
    if(currentFixedCharacterIdx == inputString.length()){
        cout<<inputString<<"\n";
        return;
    }

    for(int j=currentFixedCharacterIdx; j<inputString.length(); j++){
        swap(inputString[currentFixedCharacterIdx], inputString[j]);
        findAndPrintStringPermutations(inputString, currentFixedCharacterIdx+1);
        swap(inputString[j], inputString[currentFixedCharacterIdx]);
    }
}

int main(){

    string inputString;
    while(true){
        cout<<"Enter the input string for printing all the permutations: ";
        cin>>inputString;
        cout<<"All the permutations of the given string are:\n";
        findAndPrintStringPermutations(inputString);
    }
    return 0;
}