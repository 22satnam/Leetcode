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
public:
    bool isValidBST(TreeNode* root) {
        long mini = LONG_MIN;
        long maxi = LONG_MAX;
        
        return check(root,mini,maxi);
        
    }
    bool check(TreeNode* root, long mini, long maxi){
        if(root == NULL)return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return check(root->left,mini,root->val) &&
               check(root->right,root->val,maxi);
    }
};