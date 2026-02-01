class Solution {
public:
    int bfs(vector<vector<int>>&adj){
        int count=0;
        vector<bool >visit(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(visit[i]){
                continue;
            }
            count++;
            visit[i]=true;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int nei:adj[node]){
                    if(!visit[nei]){

                        q.push(nei);
                        visit[nei]=true;
                    }
                }
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j&&isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        return bfs(adj);
    }
};