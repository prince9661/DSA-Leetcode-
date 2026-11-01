class Solution {
public:
    int mod = 1e9 +7;
    int solve(int i,int j,int dir,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i>=grid.size() ||j>=grid[0].size())return 0;
        if(i== grid.size()-1 && j== grid[0].size()-1)return 1;
        if(dp[i][j][dir]!=-1)return dp[i][j][dir];
        if(grid[i][j]==1){
            if(dir ==0){
                return dp[i][j][dir]= solve(i+1,j,1,grid,dp);
            }else{
                return dp[i][j][dir]= solve(i,j+1,0,grid,dp);
            }
        }
        return dp[i][j][dir] = (solve(i,j+1,0,grid,dp)+ solve(i+1,j,1,grid,dp))%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(2,-1)));
        return solve(0,0,0,grid,dp);
    }
};