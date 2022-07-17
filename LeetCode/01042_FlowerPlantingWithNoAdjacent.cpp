// https://leetcode.com/problems/flower-planting-with-no-adjacent/

// Greedy solution: Taken from LeetCode discuss page
class Solution {
private:
    void plantFlowers(vector<int>& plantedFlowers,
                     vector<vector<int>>& gardenConfig,
                     int numGardens) {
        
        for(int currGarden = 0; currGarden < numGardens; currGarden++) {
            vector<int> usedFlowers(5, -1);
            // Mark all the flowers used by gardens connected to currGarden
            for(int connectedGarden : gardenConfig[currGarden])
                if(plantedFlowers[connectedGarden] != -1)
                    usedFlowers[plantedFlowers[connectedGarden]] = 1;
            
            // Plant a flower which is not used by any garden connected to currGarden
            for(int flowerType = 1; flowerType <=4; flowerType++)
                if(usedFlowers[flowerType] != 1) {
                    plantedFlowers[currGarden] = flowerType;
                    break;
                }
        }
    }
    
public:
    vector<int> gardenNoAdj(int numGardens, vector<vector<int>>& paths) {
        vector<vector<int>> gardenConfig(numGardens);
        vector<int> plantedFlowers(numGardens, -1);
        
        // Create 2D graph
        for(vector<int> currPath : paths) {
            gardenConfig[currPath[0] - 1].push_back(currPath[1] - 1);
            gardenConfig[currPath[1] - 1].push_back(currPath[0] - 1);
        }
            
        plantFlowers(plantedFlowers, gardenConfig, numGardens);
        return plantedFlowers;
    }
};


// Simple back-tracking solution: Gives TLE
class Solution {
private:
    bool isSafeToColor(int currColor, int nodeToColor,
                      vector<int>& coloredNodes,
                      vector<vector<int>>& graph, int numNodes) {
        
        for(int currNode = 0; currNode < numNodes; currNode++) {
            if(currNode != nodeToColor) // nodeToColor is yet to be colored, checking for all other nodes
                for(auto connectedNode : graph[currNode]) // Checking if currNode is connected to nodeToColor
                    if(connectedNode == nodeToColor &&
                       coloredNodes[currNode] == currColor) // If currNode is having the same color is the color 
                                                                //we were going to pain nodeToColor with
                        return false;
        }
        return true;
    }

    
    bool solveMColoringProblem(int currNode, vector<int>& coloredNodes,
                               vector<vector<int>>& graph,
                               int numNodes, int numColors) {
        if(currNode == numNodes)
            return true;
        
        for(int currColor = 1; currColor <= numColors; currColor++) {
            if(isSafeToColor(currColor, currNode, coloredNodes, graph, numNodes)) {
                coloredNodes[currNode] = currColor;
                
                if(solveMColoringProblem(currNode+1, coloredNodes, graph, numNodes, numColors))
                    return true;
                
                coloredNodes[currNode] = -1;
            }
        }
        
        return false;
    }
    
public:
    vector<int> gardenNoAdj(int numGardens, vector<vector<int>>& paths) {
        vector<vector<int>> gardenConfig(numGardens);
        vector<int> plantedFlowers(numGardens, -1);
        int gardenIdxForPlanting = 0;
        
        // Create 2D graph
        for(vector<int> currPath : paths) {
            gardenConfig[currPath[0] - 1].push_back(currPath[1] - 1);
            gardenConfig[currPath[1] - 1].push_back(currPath[0] - 1);
        }
            
        solveMColoringProblem(gardenIdxForPlanting, plantedFlowers, gardenConfig, numGardens, 4);
        return plantedFlowers;
    }
};