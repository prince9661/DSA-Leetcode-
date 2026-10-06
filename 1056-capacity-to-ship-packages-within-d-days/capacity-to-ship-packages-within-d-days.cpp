class Solution {
public:
    bool check(vector<int>&weight, int t ,int d){
        int s =0;
        for(int w: weight){
            s+=w;
            if(s>t){
                d--;
                s=w;
            }
        }
        if(d<=0)return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l =0;
        int r = 0;
        int ans =INT_MAX;
        for(int w: weights){
            r+=w;
            l = max(l,w);
        }
        while(l<= r){
            int mid = l+(r-l)/2;
            bool ispossible = check(weights,mid,days);
            if(ispossible){
                ans = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};