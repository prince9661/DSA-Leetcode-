class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l =0;
        int n = nums.size();
        int r=n-1;
        if(n==1)return nums[0];
        if(nums[0]!= nums[1])return nums[0];
        if(nums[r]!= nums[r-1])return nums[r];
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]!= nums[mid-1] && nums[mid]!= nums[mid+1])return nums[mid];
            if(mid%2==0 ){
                if(nums[mid]==nums[mid -1]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(nums[mid]!= nums[mid-1]){
                    r = mid -1;
                }else{
                    l = mid+1;
                }
            }
        }
        return 0;
    }
};