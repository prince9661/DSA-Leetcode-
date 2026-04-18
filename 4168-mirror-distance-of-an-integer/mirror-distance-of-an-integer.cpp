class Solution {
public:
    int mirrorDistance(int n) {
        int k=n;
        int rev=0;
        while(k>0){
            rev=rev*10+(k%10);
            k/=10;
        }
        return abs(rev-n);
    }
};