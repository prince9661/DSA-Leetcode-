class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> >q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        while(!q.empty()){
            int n=q.size();
            count++;
            for(int i=0;i<n;i++){
                auto [x,y]=q.front();
                q.pop();
                if(x>0&&grid[x-1][y]==1){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(x<grid.size()-1 && grid[x+1][y]==1){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(y>0&&grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                if(y<grid[x].size()-1 && grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return (count==0)?0:count-1;
    }
};