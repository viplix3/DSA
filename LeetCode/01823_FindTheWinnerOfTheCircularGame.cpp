// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Josephus problem solution
class Solution {
private:
    int solveJosephusProblem(int n, int k) {
        if(n == 1)
            return 0;
        return (solveJosephusProblem(n-1, k) + k) % n;
        
    }
public:
    int findTheWinner(int n, int k) {
        return solveJosephusProblem(n, k) + 1;
    }
};