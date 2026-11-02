class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        
        int median=nums[n/2];
        for(int i=0;i<n;i++){
            count+=abs(median-nums[i]);
        }
        return count;
    }
};