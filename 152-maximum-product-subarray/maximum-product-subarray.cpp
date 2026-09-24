class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mul = 1;
        long long mx= INT_MIN;
        for(int num : nums){
            mul*= num;
            mx = max(mx,mul);
            if(num == 0)mul =1;
        }
        mul =1;
        for(int i=nums.size()-1;i>=0;i--){
            mul*= nums[i];
            mx = max(mx,mul);
            if(nums[i]==0) mul =1;
        }
        return mx;
    }
};