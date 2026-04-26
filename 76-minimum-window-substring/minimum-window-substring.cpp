class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int n=t.size();
        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
        int l=0;
        int count=0;
        n=mp.size();
        // int si=-1;
        // int length=INT_MAX;
        pair<int,int> ans={INT_MAX,-1};
        for(int r=0;r<s.size();r++){
            mp[s[r]]--;
            if(mp[s[r]]==0)count++;
            while(count>=n){
                if(r-l+1<ans.first){
                    ans.first=r-l+1;
                    ans.second=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)count--;
                l++;
            }
        }
        if(ans.second==-1)return "";
        return s.substr(ans.second,ans.first);
    }
};