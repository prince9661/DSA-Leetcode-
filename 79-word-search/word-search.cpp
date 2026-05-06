class Solution {
public:
    bool solve(int p,int i,int j,vector<vector<bool>>&visit, vector<vector<char>>&board,string &word){
        if(p==word.size())return true;
        if(i<0 || j<0||i>=board.size()||j>=board[0].size())return false;
        if(visit[i][j]==true)return false;
        if(board[i][j]!=word[p])return false;
        visit[i][j]=true;
        
        bool b=solve(p+1,i+1,j,visit,board,word);
        bool a=solve(p+1,i-1,j,visit,board,word);
        bool c=solve(p+1,i,j+1,visit,board,word);
        bool d=solve(p+1,i,j-1,visit,board,word);
        visit[i][j]=false;
        return a|| b||c||d;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                vector<vector<bool>>visit(board.size(),vector<bool>(board[0].size()));
                if(solve(0,i,j,visit,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};