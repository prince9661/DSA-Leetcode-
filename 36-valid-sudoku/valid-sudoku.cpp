class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>>mp;
        unordered_map<int,unordered_set<char>>mp2;
        unordered_map<int,unordered_set<char>>box;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(mp[i].count(board[i][j])){
                        return false;
                    }
                    mp[i].insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    if(mp2[i].count(board[j][i])){
                        return false;
                    }
                    mp2[i].insert(board[j][i]);
                }
                if(board[i][j]!='.'){
                    int idx=(i/3)*3 +(j/3);
                    if(box[idx].count(board[i][j]))return false;
                    box[idx].insert(board[i][j]);
                }

            }
        }
        return true;
        
    }
};