class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int res=sum-k;
            ans+=mp[res];
            mp[sum]++;
        }
        return ans;
    }
};