class Solution {
public:
    unordered_map<char,string>mp;
    vector<string>ans;
    void solve(int i,string &s,string &res){
        if(i==s.size()){
            ans.push_back(res);
            return;
        }
        for(int j=0;j<mp[s[i]].size();j++){
            res+=mp[s[i]][j];
            solve(i+1,s,res);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string res="";
        solve(0,digits,res);
        return ans;
    }
};