// https://leetcode.com/problems/split-linked-list-in-parts/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
	int getListLen(ListNode* head) {
		int listLen = 0;

		while(head) {
			head = head->next;
			listLen++;
		}

		return listLen;
	}

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> splitList;

		int listLen = getListLen(head);
		int numNodesPerPart = listLen / k;
		int numExtraNodes = listLen % k;
        int currNodeIdx = 0;
		ListNode *currNode = head, *prevNode = nullptr;

		while(currNodeIdx < listLen && currNode != nullptr) {
			int currPartLen = 0;
			splitList.push_back(currNode);

			while(currPartLen < numNodesPerPart) {
                prevNode = currNode;
				currNode = currNode->next;
				currPartLen++;
			}

			if(numExtraNodes > 0) {
                prevNode = currNode;
				currNode = currNode->next;
				currPartLen++;
				numExtraNodes--;
			}
            
            currNodeIdx += currPartLen;
            prevNode->next = nullptr;
		}

		while(splitList.size() < k) {
			splitList.push_back(nullptr);
		}

		return splitList;
    }
};