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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i = 0; i < inorder.size(); i++){
            inmap[inorder[i]] = i;   
        }
        TreeNode* root = helper(preorder, 0, preorder.size()-1,
                                 inorder, 0, inorder.size()-1, inmap);
        return root;
        
    }
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd, map<int,int>& inmap){
        
        if(preStart > preEnd || inStart > inEnd)return NULL; //for returning when null
        TreeNode* root = new TreeNode(preorder[preStart]); // making the prestart the root
        
        int inroot = inmap[root->val];
        int numsleft = inroot - inStart;
        
        root->left = helper(preorder, preStart+1, preStart+numsleft, 
                            inorder, inStart, inroot-1, inmap);
        
        root->right = helper(preorder, preStart+numsleft+1, preEnd,
                             inorder, inroot+1, inEnd, inmap);
        return root;
    }
};