class Solution {
private:
    int solve(vector<int>&nums,int k){
        if(k<0)return 0;
        int sum=0;
        int n=nums.size();
        int ans=0;
        int s=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)sum++;
            while(sum>k){
                if(nums[s]==1){
                    sum--;
                }
                s++;
            }
            ans+=i-s+1;
        }
        return ans;
    }
public:
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};