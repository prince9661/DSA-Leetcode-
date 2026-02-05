class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i< prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        stack<int>s;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)s.push(i);
        }
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(int nig:adj[node]){
                indegree[nig]--;
                if(indegree[nig]==0)s.push(nig);
            }
            
        }
        for(int i:indegree){
            if(i!=0)return false;
        }
        return true;
    }
};