class Solution {
public:
    int characterReplacement(string s, int k) {
        // unordered_map<char,int>mp;
        vector<int>freq(26,0);
        int n=s.size();
        int st=0;
        int ans=0;
        // unordered_set<char>st;
        int maxcount=0;
        for(int e=0;e<n;e++){
            // st.insert(s[i]);
            freq[s[e]-'A']++;
            maxcount=max(maxcount,freq[s[e]-'A']);
            while(e-st+1>maxcount+k){
                freq[s[st]-'A']--;
                st++;
            }
            ans=max(ans,e-st+1);
            
        }
        return ans;

    }
};