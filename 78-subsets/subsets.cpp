class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>&res,vector<int>&nums){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        solve(i+1,res,nums);
        res.push_back(nums[i]);
        solve(i+1,res,nums);
        res.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        solve(0,res,nums);
        return ans;
        
    }
};