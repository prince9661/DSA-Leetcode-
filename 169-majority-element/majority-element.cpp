class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        int count=0;
        for(int num:nums){
            if(element==num){
                count++;
            }
            else{
                count--;
            }
            if(count<1){
                element=num;
                count=1;
            }
        }
        return element;
    }
};