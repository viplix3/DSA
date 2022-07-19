// https://leetcode.com/problems/permutation-sequence/

// Striver's solution
class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> numbers;
        
        for(int i = 1; i < n; i++) {
            factorial *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        string KthPermutation = "";
        k = k-1; // For 0-based indexing
        
        while(true) {
            KthPermutation = KthPermutation + to_string(numbers[k / factorial]);
            numbers.erase(numbers.begin() + k / factorial);
            
            if(numbers.size() == 0)
                break;
            
            k = k % factorial;
            factorial = factorial / numbers.size();
        }
        
        return KthPermutation;
    }
};