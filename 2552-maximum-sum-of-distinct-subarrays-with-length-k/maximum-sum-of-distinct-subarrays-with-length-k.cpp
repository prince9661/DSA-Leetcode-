class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long sum=0;
        int j=0;
        unordered_set<int>st;
        int i=0;
        while(j<n){
            while(st.size()<k&&j<n){
                if(st.count(nums[j])){
                    while(nums[i]!=nums[j]){
                        sum-=nums[i];
                        st.erase(nums[i]);
                        i++;
                        
                    }
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                st.insert(nums[j]);
                sum+=nums[j];
                j++;
            }
            if(st.size()==k){
                ans=max(ans,sum);
                sum-=nums[i];
                st.erase(nums[i]);
                
                
            }
            i++;
        }
        return ans;
    }
};