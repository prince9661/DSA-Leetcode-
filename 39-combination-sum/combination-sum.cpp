class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int target,vector<int>&res,vector<int>&nums){
        if(i>=nums.size())return;
        if(target<0)return;
        if(target==0){
            ans.push_back(res);
            return;
        }

        solve(i+1,target,res,nums);
        res.push_back(nums[i]);
        solve(i,target-nums[i],res,nums);
        
        res.pop_back();
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        sort(candidates.begin(),candidates.end());
        solve(0,target,res,candidates);
        return ans;
    }
};