class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s=0;
        int e=0;
        int n=nums.size();
        int ans=0;
        int count=0;
        while(e<n){
            if(nums[e]==0){
                count++;
            }
            while(count>k){
                if(nums[s]==0){
                    count--;
                }
                s++;
            }
            ans=max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};