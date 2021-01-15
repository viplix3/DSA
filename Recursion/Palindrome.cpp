#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const char *string, int minVal, int maxVal)
{
    if(string[minVal] != string[maxVal])
        return false;

    if(minVal >= maxVal)
        return true;

    return isPalindrome(string, minVal+1, maxVal-1);
}

int main(){

    while(true){
        cout<<"Enter input string or type -1 to exit: ";
        string inputString;
        cin>>inputString;
        if(inputString == "-1")
            break;
        cout<<"Is input string "<<inputString<<" palindrome: "<<isPalindrome(inputString.c_str(), 0, inputString.size()-1)<<endl;
    }

    return 0;
}