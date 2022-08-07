// https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traverseInOrder(vector<int>& inorder, TreeNode* root) {
        if(root == nullptr)
            return;
        
        traverseInOrder(inorder, root->left);
        inorder.push_back(root->val);
        traverseInOrder(inorder, root->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        traverseInOrder(inOrder, root);
        
        return inOrder;
    }
};