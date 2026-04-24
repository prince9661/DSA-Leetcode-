class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int l=0;
        int n=s.size();
        vector<int>fre(3);
        for(int r=0;r<n;r++){
            fre[s[r]-'a']++;
            while(fre[0]>0&& fre[1]>0 && fre[2]>0){
                ans+=n-r;
                fre[s[l]-'a']--;
                l++;
            }


        }
        return ans;
    }
};