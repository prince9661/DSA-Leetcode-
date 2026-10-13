class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int st =0;
        int ans = INT_MAX;
        int count =0;
        for(int end = 0;end<blocks.size();end++){
            if(blocks[end]=='W')count++;
            if(end-st+1<k)continue;
            if(end-st +1>k){
                if(blocks[st]=='W'){
                    count--;
                    
                }
                st++;
            }
            ans=min(ans,count);
        }
        return ans;
    }
};