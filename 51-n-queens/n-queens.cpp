class Solution {
public:
    bool check(int i,int j,vector<string>&board){
        for(int k=0;k<i;k++){
            if(board[k][j]=='Q')return false;

        }
        int r=i;
        int c=j;
        while(r>=0 &&c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }
        r=i;
        c=j;
        while(r>=0&&c<board.size()){
            if(board[r][c]=='Q')return false;
            r--;
            c++;
        }
        return true;
        
    }
    vector<vector<string>>ans;
    void solve(int i,vector<string>&board,int n){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(check(i,j,board)){
                board[i][j]='Q';
                solve(i+1,board,n);
                board[i][j]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string a="";
        for(int i=0;i<n;i++){
            a+=".";
        }
        vector<string>board(n,a);
        solve(0,board,n);
        return ans;
    }
};