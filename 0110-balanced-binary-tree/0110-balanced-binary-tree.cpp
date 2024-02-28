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
    int depth(TreeNode* root){
        if(root == NULL)return 0;
    int lh = depth(root -> left);
    int rh = depth(root ->right);
        if(lh == -1 || rh == -1)return -1;
        if(abs(lh-rh) > 1)return -1;
        
        return 1 + max(lh,rh);
        
    }
    bool isBalanced(TreeNode* root) {

        int ans = depth(root);
        if(ans == -1)return false;
        return true;
        
        
    }
};