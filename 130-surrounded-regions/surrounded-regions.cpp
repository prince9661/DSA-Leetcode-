class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector< bool>>visit(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                visit[i][0]=true;
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
                visit[i][n-1]=true;
                q.push({i,n-1});
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                visit[0][j]=true;
                q.push({0,j});
            }
            if(board[m-1][j]=='O'){
                visit[m-1][j]=true;
                q.push({m-1,j});
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            int r[4]={-1,1,0,0};
            int c[4]={0,0,-1,+1};
            for(int k=0;k<4;k++){
                int i=x+r[k];
                int j=y+c[k];
                if(i>=0&&j>=0&&i<m&&j<n){
                    if(!visit[i][j] && board[i][j]=='O'){
                        q.push({i,j});
                        visit[i][j]=true;
                    }
                }
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!visit[i][j]&&board[i][j]=='O')board[i][j]='X';
            }
        }

    }
};