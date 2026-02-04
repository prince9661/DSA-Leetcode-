class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visit[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            // auto [[i,j],dis]=q.front();
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            ans[i][j]=dis;
            q.pop();
            if(i>0 && !visit[i-1][j]){
                q.push({{i-1,j},dis+1});
                visit[i-1][j]=true;
            }
            if(i>0 && !visit[i-1][j]){
                q.push({{i-1,j},dis+1});
                visit[i-1][j]=true;
            }
            if(j>0 && !visit[i][j-1]){
                q.push({{i,j-1},dis+1});
                visit[i][j-1]=true;
            }
            if(i<m-1 && !visit[i+1][j]){
                q.push({{i+1,j},dis+1});
                visit[i+1][j]=true;
            }
            if(j<n-1 && !visit[i][j+1]){
                q.push({{i,j+1},dis+1});
                visit[i][j+1]=true;
            }
            

        }
        return ans;
    }
};