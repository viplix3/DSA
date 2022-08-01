// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Minimum pages allocation using binary search: O(N log(arraySum))
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minAllocation = weights[0], maxAllocation = weights[0];
        int numWeights = weights.size();
        
        // Lambda function to check if shipCapacity can carry all the packages
        auto canShipPackages = [&](int shipCapacity, int days) {
            int currShipCapacity = shipCapacity;
            
            for(int i = 0; i < numWeights; i++) {
                if(weights[i] <= currShipCapacity)
                    currShipCapacity -= weights[i];
                else {
                    days--;
                    currShipCapacity = shipCapacity - weights[i];
                }
                
                if(days <= 0)
                    return false;
            }
            
            return true;
        };
        
        
        for(int i = 1; i < numWeights; i++) {
            minAllocation = max(weights[i], minAllocation);
            maxAllocation += weights[i];
        }
        
        int minShipCapacity;
        while(minAllocation <= maxAllocation) {
            int currShipCapacity = minAllocation + (maxAllocation - minAllocation) / 2;
            
            if(canShipPackages(currShipCapacity, days)) {
                minShipCapacity = currShipCapacity;
                maxAllocation = currShipCapacity - 1;
            }
            else
                minAllocation = currShipCapacity + 1;
        }
        
        return minShipCapacity;
    }
};