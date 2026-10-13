class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=blocks.size();
        int ans = INT_MAX;

        for(int st =0;st<l-k+1;st++){
            int count =0;
            for(int i=st;i<k+st;i++){
                if(blocks[i]=='W'){
                    
                    count++;
                }
            }
            ans = min(ans,count);
        }
        return ans;

        
    }
};