class Solution {
public:
    bool ispalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve(int i, string &s,vector<string>&res){
        if(i==s.size()){
            ans.push_back(res);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                res.push_back(s.substr(i, j - i + 1));
                solve(j+1,s,res);
                res.pop_back();
            }
            else{
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>res;
        solve(0,s,res);
        return ans;
    }
};