class Solution {
public:
    string minWindow(string s, string t) {
        int totalChar = 0;
        unordered_map<char,int>mp;
        for(char c : t){
            if(mp[c]==0)totalChar++;
            mp[c]++;
        }
        int st = 0;
        pair<int,int> ans={INT_MAX,-1};
        for(int end = 0; end < s.size(); end++){
            mp[s[end]]--;
            if(mp[s[end]] == 0)totalChar--;
            while(totalChar <= 0){
                if(end-st+1 <ans.first){
                    ans.first = end - st +1;
                    ans.second = st;
                }
                mp[s[st]]++;
                if(mp[s[st]]>0)totalChar++;
                st++;
            }
        }
        if(ans.second==-1)return "";
        return s.substr(ans.second,ans.first);
    }
};