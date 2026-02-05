class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int >indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int >ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int nig:adj[node]){
                indegree[nig]--;
                if(indegree[nig]==0){
                    q.push(nig);
                }
            }
        }
        if(ans.size()==numCourses)return ans;
        return {};
    }
};