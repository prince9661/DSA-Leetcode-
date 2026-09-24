class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n= nums.size();
        int n1= nums[0];
        int n2 = nums[0];
        int c1 = 0;
        int c2 = 0;
        for( int num : nums){
            if(num == n1){
                c1++;
            }else if(num == n2){
                c2++;
            }else if(c1 == 0){
                n1 = num;
                c1=1;
            }else if(c2 == 0){
                n2 = num;
                c2 =1;
            }else{
                c1--;
                c2--;
            }
        }
        int v1 = 0;
        int v2 =0;
        for(int num : nums){
            if(num == n1){
                v1++;
            }else if(num == n2)v2++;
        }
        if(v1>n/3)ans.push_back(n1);
        if(v2>n/3)ans.push_back(n2);
        return ans;
    }
};