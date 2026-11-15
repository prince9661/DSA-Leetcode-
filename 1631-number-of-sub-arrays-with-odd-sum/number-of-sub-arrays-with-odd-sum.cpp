class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int odd = 0;
        int even = 0;
        for(int num: arr){
            if(num%2 ==0){
                ans = (ans+odd)%mod;
                even = (even+1)%mod;
            }else{
                int temp = even;
                even = odd;
                odd = (temp+1)%mod;

                ans = (ans+odd)%mod;
            }
        }
        return ans;
    }
};