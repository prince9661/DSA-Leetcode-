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
    bool solve(TreeNode * first,TreeNode* second){
        if(first==nullptr && second ==nullptr)return true;
        if(first==nullptr || second ==nullptr)return false;

        if(first->val!=second->val)return false;
        bool l=solve(first->left, second->right);
        bool r=solve(first->right,second->left);
        if(l==true && r==true)return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr )return true;
        return solve(root->left,root->right);
    }
};