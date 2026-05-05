class Solution {
public:
    vector<vector<int>>ans;
    // void solve(int i,vector<int>&res,vector<int>&nums){
    //     ans.push_back(res);
        
    //     for(int j=i;j<nums.size();j++){
    //         if(j>i&&nums[j]==nums[j-1])continue;
    //         res.push_back(nums[j]);
    //         solve(j+1,res,nums);
    //         res.pop_back();
    //     }
        
    // }
    void solve(int i,vector<int>&res,vector<int>&nums,unordered_set<int>&st){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        if(!st.count(nums[i])){
            solve(i+1,res,nums,st);

        }
        st.insert(nums[i]);
        res.push_back(nums[i]);
        solve(i+1,res,nums,st);
        res.pop_back();
        st.erase(nums[i]);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        unordered_set<int>st;
        solve(0,res,nums,st);
        return ans;
    }
};