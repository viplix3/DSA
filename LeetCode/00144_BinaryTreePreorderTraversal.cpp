// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void traversePreOrder(vector<int>& preOrder, TreeNode* root) {
        if(root == nullptr)
            return;
        preOrder.push_back(root->val);
        traversePreOrder(preOrder, root->left);
        traversePreOrder(preOrder, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        traversePreOrder(preOrder, root);
        return preOrder;
    }
};