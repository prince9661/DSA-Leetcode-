class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& grap) {
        int n=grap.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<grap[i].size();j++){
                graph[grap[i][j]].push_back(i);
            }
        }
        vector<int>indegree(n,0);
        


        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[graph[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nig : graph[node]){
                indegree[nig]--;
                if(indegree[nig]==0)q.push(nig);
            }
        }
        vector<int >ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};