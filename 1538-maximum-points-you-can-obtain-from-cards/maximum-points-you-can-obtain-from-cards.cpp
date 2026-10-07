class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0;
        int kthSum = 0;
        int kth=cardPoints.size() -k;
        for(int i = 0; i< cardPoints.size();i++){
            totalSum += cardPoints[i];
            if(i<kth){
                kthSum+=cardPoints[i];
            }
        }
        int ans = kthSum;
        int res = ans;
        for(int i=0;i<k;i++){
            ans-=cardPoints[i];
            ans+=cardPoints[kth + i];
            res = min(ans,res);
        }
        return totalSum - res;
    }
};