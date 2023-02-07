#include <iostream>
#include <vector>
#include <cassert>

int findNumJumpSequences(std::vector<int> &allowedJumps, int targetDistance)
{
    // O(K^N) time complexity where K is the number of allowed jumps and N is the target distance
    if (targetDistance == 0) // Reached the target distance
        return 1;

    if (targetDistance < 0) // Overshot the target distance
        return 0;

    int count = 0;
    for (int jumpSize : allowedJumps)
        count += findNumJumpSequences(allowedJumps, targetDistance - jumpSize);

    return count;
}

int findNumJumpSequencesDP(std::vector<int> &allowedJumps, int targetDistance)
{
    // O(KN) time complexity where K is the number of allowed jumps and N is the target distance
    std::vector<int> numPossibilitiesToReach(targetDistance + 1, 0);
    numPossibilitiesToReach[0] = 1;

    for (int currTarget = 1; currTarget <= targetDistance; currTarget++)
    {
        for (int jumpSize : allowedJumps)
        {
            // It is possible to make the jump and not overshoot the currTarget distance
            if (currTarget - jumpSize >= 0)
                // Number of ways to reach the currTarget distance is the sum of the number of ways to reach the currTarget distance
                // when making a jump of size jumpSize and the number of ways to reach currTarget - jumpSize distance
                numPossibilitiesToReach[currTarget] += numPossibilitiesToReach[currTarget - jumpSize];
        }
    }

    return numPossibilitiesToReach[targetDistance];
}

std::ostream &operator<<(std::ostream &outStream, std::vector<int> outData)
{
    for (int data : outData)
        outStream << data << " ";
    return outStream;
}

void executeTests()
{
    std::vector<int> allowedJumps;
    int targetDistance, possibleJumpSequences;

    // Recursive solution test
    allowedJumps = {1, 2, 3};
    targetDistance = 3;
    possibleJumpSequences = findNumJumpSequences(allowedJumps, targetDistance);
    assert(possibleJumpSequences == 4);
    std::cout << "Number of jump sequences to reach the target distance " << targetDistance << " with allowed jump sizes " << allowedJumps << ": " << possibleJumpSequences << std::endl;

    // DP solution test
    allowedJumps = {2, 3, 5};
    targetDistance = 5;
    possibleJumpSequences = findNumJumpSequencesDP(allowedJumps, targetDistance);
    assert(possibleJumpSequences == 3);
    std::cout << "Number of jump sequences to reach the target distance " << targetDistance << " with allowed jump sizes " << allowedJumps << ": " << possibleJumpSequences << std::endl;

    allowedJumps = {3, 5, 10};
    targetDistance = 20;
    possibleJumpSequences = findNumJumpSequencesDP(allowedJumps, targetDistance);
    assert(possibleJumpSequences == 11);
    std::cout << "Number of jump sequences to reach the target distance " << targetDistance << " with allowed jump sizes " << allowedJumps << ": " << possibleJumpSequences << std::endl;
}

int main()
{
    const int numAllowedJumps = 3;
    std::vector<int> allowedJumps;
    int targetDistance, possibleJumpSequences;

    std::cout << "Running tests..." << std::endl;
    executeTests();
    std::cout << "Tests passed!" << std::endl;

    std::cout << "Running user input tests..." << std::endl;
    std::cout << "Enter number of test cases: ";
    int numTestCases;
    std::cin >> numTestCases;

    while (numTestCases--)
    {
        std::cout << "Enter allowed jump sizes (K, L, M): ";
        allowedJumps.clear();
        for (int i = 0; i < numAllowedJumps; i++)
        {
            int jumpSize;
            std::cin >> jumpSize;
            allowedJumps.push_back(jumpSize);
        }

        std::cout << "Enter target distance: ";
        std::cin >> targetDistance;

        possibleJumpSequences = findNumJumpSequencesDP(allowedJumps, targetDistance);
        std::cout << "Number of jump sequences to reach the target distance " << targetDistance << " with allowed jump sizes " << allowedJumps << ": " << possibleJumpSequences << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
