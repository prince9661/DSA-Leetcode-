class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int target,vector<int>&res,vector<int>&nums){
        
        if(target<0)return;
        if(target==0){
            ans.push_back(res);
            return;
        }
        if(i>=nums.size())return;
        
        for(int j=i;j<nums.size();j++){
            if(j>i &&nums[j]==nums[j-1])continue;
            res.push_back(nums[j]);
            solve(j+1,target-nums[j],res,nums);
            res.pop_back();
        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>res;
        sort(candidates.begin(),candidates.end());
        solve(0,target,res,candidates);
        return ans;
    }
};