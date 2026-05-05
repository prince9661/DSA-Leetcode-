class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k,int i,int n,vector<int>&res){
        
        if(k==0&&n==0){
            ans.push_back(res);
            return;
        }
        if(i>9)return;
        if(k<0||n<0)return;
        solve(k,i+1,n,res);
        res.push_back(i);
        solve(k-1,i+1,n-i,res);
        res.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45)return ans;
        vector<int>res;
        solve(k,1,n,res);
        return ans;
    }
};