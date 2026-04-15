class Solution {
public:
    int totalFruit(vector<int>& fruts) {
        unordered_map<int,int>mp;
        int s=0;
        int ans=0;
        for(int e=0;e<fruts.size();e++){
            mp[fruts[e]]++;
            while(mp.size()>2){
                mp[fruts[s]]--;
                if(mp[fruts[s]]==0){
                    mp.erase(fruts[s]);
                }
                s++;
            }
            ans=max(ans,e-s+1);
        }
        return ans;
    }
};