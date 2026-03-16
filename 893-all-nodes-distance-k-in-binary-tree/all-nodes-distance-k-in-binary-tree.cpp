/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> bfs(TreeNode * target,int k,unordered_map<TreeNode* ,TreeNode *>mp){
        queue<TreeNode*>q;
        q.push(target);
        vector<int>v;
        vector<bool>visit(501);
        visit[target->val]=true;
        while(!q.empty()){
            int n=q.size();
            
            if(k<=0){
                while(!q.empty()){
                    v.push_back(q.front()->val);
                    q.pop();
                }
                return v;
            }
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=nullptr&& visit[curr->left->val]==false){
                    q.push(curr->left);
                    visit[curr->left->val]=true;
                }
                if(curr->right!=nullptr && visit[curr->right->val]==false){
                    q.push(curr->right);
                    visit[curr->right->val]=true;
                }
                if(mp[curr]!=nullptr &&visit[mp[curr]->val]==false){
                    q.push(mp[curr]);
                    visit[mp[curr]->val]=true;
                }
            }
            k--;
            
            
        }
        return v;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *>mp;
        mp[root]=nullptr;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode * parent=st.top();
            st.pop();
            if(parent->left!=nullptr){
                st.push(parent->left);
                mp[parent->left]=parent;
            }
            if(parent->right!=nullptr){
                st.push(parent->right);
                mp[parent->right]=parent;
            }
        }
        return bfs(target,k,mp);
    }
};