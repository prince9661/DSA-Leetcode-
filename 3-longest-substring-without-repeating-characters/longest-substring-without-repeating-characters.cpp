class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int i=0;
        int ans=0;
        for(int e=0;e<s.size();e++){
            if(!st.count(s[e])){
                ans=max(ans,e-i+1);
                st.insert(s[e]);
            }else{
                while(st.count(s[e])){
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[e]);
            }
        }
        return ans;
    }
};