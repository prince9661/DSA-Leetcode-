class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sumsource=0;
        long long sumtarget = 0;
        for(int i=0;i<source.size();i++){
            sumsource+=source[i];
            sumtarget += target[i];
        }
        if(sumsource ==sumtarget)return true;
        return false;
    }
};