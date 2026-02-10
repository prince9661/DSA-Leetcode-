class Solution {
public:
    void solve(int n,int idx,vector<vector<int>>& graph,vector<int>&v,vector<vector<int>>&ans){
        if(idx==n-1){
            ans.push_back(v);
            return;
        }

        for(int i =0;i<graph[idx].size();i++){
            v.push_back((graph[idx][i]));
            solve(n,graph[idx][i],graph,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>v;
        v.push_back(0);
        int n=graph.size();
        solve(n,0,graph,v,ans);
        return ans;
    }
};