class Solution {
public:
    vector<string>ans;
    // void solve(int i,int n,string &s){
    //     if(s.size()>n)return;
    //     if(s.size()==n&& i<1)return;
    //     if(s.size()==n&&i>0){
    //         ans.push_back(s);
    //         return;
    //     }
    //     s+="0";
    //     solve(i,n,s);
    //     s.pop_back();
    //     s+="1";
    //     solve(i+1,n,s);
    //     s.pop_back();
    // }
    void solve(bool i,int n,string &s){
        if(s.size()>n)return;
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        s+="1";
        solve(true,n,s);
        s.pop_back();
        if(i==true){
            s+="0";
            solve(false,n,s);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string s="";
        // solve(0,n,s);
        solve(true,n,s);
        return ans;
    }
};