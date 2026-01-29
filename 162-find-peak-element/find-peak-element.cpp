class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1;
        int r=nums.size()-2;
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[r]<nums[r+1])return r+1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
            if(nums[mid]<nums[mid-1]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};