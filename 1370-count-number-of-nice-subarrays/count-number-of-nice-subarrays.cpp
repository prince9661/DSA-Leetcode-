class Solution {
public:
    int noOfSubarrayAtleastKOddNo(vector<int>& nums, int k){
        int st = 0;
        int oddCount = 0;
        int ans = 0;
        for(int end = 0; end<nums.size(); end++){
            if(nums[end]%2 != 0){
                oddCount++;
            }
            while(oddCount>k){
                if(nums[st]%2 != 0)oddCount--;
                st++;
            }
            ans+=end-st+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return noOfSubarrayAtleastKOddNo(nums,k) - noOfSubarrayAtleastKOddNo(nums,k-1);
    }
};