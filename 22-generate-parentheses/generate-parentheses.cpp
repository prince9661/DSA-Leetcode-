class Solution {
public:
    vector<string>ans;
    void solve(int i,int j,int n,string &s){
        if(j>i||i>n||j>n)return;
        if(i==n&&j==n){
            ans.push_back(s);
            return;
        }
        s+="(";
        solve(i+1,j,n,s);
        s.pop_back();
        s+=")";
        solve(i,j+1,n,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(0,0,n,s);
        return ans;
        
    }
};