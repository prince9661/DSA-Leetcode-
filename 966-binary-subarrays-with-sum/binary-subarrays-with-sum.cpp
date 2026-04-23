class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int res=sum-goal;
            ans+=mp[res];
            mp[sum]++;
        }
        return ans;
    }
};