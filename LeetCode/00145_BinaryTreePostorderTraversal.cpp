// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    void traversePostOrder(vector<int>& postOrder, TreeNode* root) {
        if(root == nullptr)
            return;
        traversePostOrder(postOrder, root->left);
        traversePostOrder(postOrder, root->right);
        postOrder.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        traversePostOrder(postOrder, root);
        return postOrder;
    }
};