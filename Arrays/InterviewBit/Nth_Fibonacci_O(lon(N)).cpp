#include<bits/stdc++.h>
using namespace std;
#define MODULO_VAL 1000000007

vector<vector <long>> matMul(vector<vector <long>> matrix_1, vector<vector <long>> matrix_2)
{   
    // Mod all the values
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++){
            matrix_1[i][j] = matrix_1[i][j] % MODULO_VAL;
            matrix_2[i][j] = matrix_2[i][j] % MODULO_VAL;
        }
    
    /*  This is standard 2x2 matrix multiplication
        Both matrices are of the form
        | matrix[0][0]  matrix[0][1] |
        | matrix[1][0]  matrix[1][1] |
    */
    vector<vector <long>> matMulResult = {{1, 1}, {1, 0}};
    matMulResult[0][0] = ((matrix_1[0][0]*matrix_2[0][0]) % MODULO_VAL + 
                            (matrix_1[0][1]*matrix_2[1][0]) % MODULO_VAL) % MODULO_VAL;
    matMulResult[0][1] = ((matrix_1[0][0]*matrix_2[0][1]) % MODULO_VAL + 
                            (matrix_1[0][1]*matrix_2[1][1]) % MODULO_VAL) % MODULO_VAL;
    matMulResult[1][0] = ((matrix_1[1][0]*matrix_2[0][0]) % MODULO_VAL + 
                            (matrix_1[1][1]*matrix_2[1][0]) % MODULO_VAL) % MODULO_VAL;
    matMulResult[1][1] = ((matrix_1[1][0]*matrix_2[0][1]) % MODULO_VAL + 
                            (matrix_1[1][1]*matrix_2[1][1]) % MODULO_VAL) % MODULO_VAL;
    return matMulResult;
    
}

vector<vector<long>> fastExponentiation(vector<vector <long>> matrix, int power)
{
    if(power==0 || power==1)
        return matrix;
    vector<vector <long>> interimPowerMatrix = fastExponentiation(matrix, power/2);
    
    if(power % 2 == 0)
        return matMul(interimPowerMatrix, interimPowerMatrix);
    else
        return matMul(matrix, matMul(interimPowerMatrix, interimPowerMatrix));
    
}

int getNthFibonacciNumber(int N)
{
    /* 
        If we multiply the 2D matrix M: {{1, 1}, {1, 0}} with itself (i.e. we calculate power(M, N)), we will get (N+1)th Fibonacci number
        as the element at entry {0, 0} of matrix M.
        Taking power of a number N times is O(N), so we will have to use fast exponentiation method to get power in O(log(N))
    */
   if(N == 0)
        return 0;
   if(N==1 || N==2)
        return 1; 
   vector<vector <long>> fibMatrix = {{1, 1}, {1, 0}};
   fibMatrix = fastExponentiation(fibMatrix, N-1);
   int NthFibNumber = fibMatrix[0][0];
   return NthFibNumber;
}

int main(){
    int FibTerm;

    FibTerm = 0;
    printf("%d-th term in Fibonacci sequence is: %d\n", FibTerm, getNthFibonacciNumber(FibTerm));

    FibTerm = 4;
    printf("%d-th term in Fibonacci sequence is: %d\n", FibTerm, getNthFibonacciNumber(FibTerm));

    FibTerm = 10;
    printf("%d-th term in Fibonacci sequence is: %d\n", FibTerm, getNthFibonacciNumber(FibTerm));

    FibTerm = 50;
    printf("%d-th term in Fibonacci sequence is: %d\n", FibTerm, getNthFibonacciNumber(FibTerm));
    return 0;
}