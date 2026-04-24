class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int ksum=0;
        for(int i=0;i<cardPoints.size()-k;i++){
            ksum+=cardPoints[i];
        }
        // cout<<ksum;
        int sum=ksum;
        for(int i=cardPoints.size()-k;i<cardPoints.size();i++){
            sum+=cardPoints[i];
        }
        // cout<<sum;
        int ans=sum-ksum;
        // cout<<ans;
        int x=0;
        for(int i=cardPoints.size()-k;i<cardPoints.size();i++){
            ksum-=cardPoints[x];
            x++;
            ksum+=cardPoints[i];
            ans=max(ans,sum-ksum);
        }
        return ans;
        
    }
};