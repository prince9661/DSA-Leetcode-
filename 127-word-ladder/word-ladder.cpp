class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(string s:wordList){
            st.insert(s);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string currword=q.front().first;
            int step=q.front().second;
            q.pop();
            if(currword==endWord)return step;
            for(int i=0;i<currword.size();i++){
                char original=currword[i];
                for(char ch='a';ch<='z';ch++){
                    currword[i]=ch;
                    if(st.find(currword)!=st.end()){
                        q.push({currword,step+1});
                        st.erase(currword);
                    }
                    currword[i]=original;
                }
            }
        }
        return 0;
    }
};