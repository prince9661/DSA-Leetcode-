class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int l=blocks.size();
        int count =INT_MAX;
        for(int i=0;i<l-k+1;i++){
             int ccount=0;
            for(int j=i;j<i+k;j++){
                if(blocks[j]=='W'){
                    ccount++;
                }
            }
            count=min(count,ccount);
        }
        return count;
        
    }
    
};