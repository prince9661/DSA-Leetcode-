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
    int diff=0;
    void solve(TreeNode * root,int mn,int mx){
        if(root==nullptr)return ;
        diff=max(diff,max(abs(root->val-mn),abs(mx-root->val)));
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        solve(root->left,mn,mx);
        solve(root->right,mn,mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val,root->val);
        return diff;
    }
};