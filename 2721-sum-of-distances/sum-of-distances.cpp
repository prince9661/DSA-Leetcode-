class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,pair<long long,int>>mp;
        unordered_map<int,pair<long long,int>>mp1;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].first+=i;
            mp[nums[i]].second++;

        }
        vector<long long>ans;

        for(int i=0;i<n;i++){
            mp1[nums[i]].first+=i;
            mp1[nums[i]].second++;
            long long res=0;
            
            res+=(mp[nums[i]].first-(1LL*i*mp[nums[i]].second))+2*((1LL*i*mp1[nums[i]].second)-mp1[nums[i]].first);
            ans.push_back(res);
        }
        return ans;
    }
};