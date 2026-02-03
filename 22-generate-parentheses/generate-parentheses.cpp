class Solution {
public:
    void solve(int n,int i,int j,string& s,vector<string>&ans){
        if(i>n||j>n ||j>i)return ;
        if(i==n&& j==n){
            ans.push_back(s);
        }
        s+='(';
        solve(n,i+1,j,s,ans);
        s.pop_back();
        s+=')';
        solve(n,i,j+1,s,ans);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string >ans;
        string s;
        solve(n,0,0,s,ans);
        return ans;
    }
};