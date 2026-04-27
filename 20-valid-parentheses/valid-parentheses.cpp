class Solution {
public:
    bool isValid(string s) {
        // if(s.size()==0)return true;
        stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     s.push(s[i]);
        // }
        st.push(s[0]);
        
        for(int i=1;i<s.size();i++){
            // char c=st.top();
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty())return false;
                char c=st.top();
                if(st.size())
                if(s[i]==')'){
                    if(c=='('){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                else if(s[i]=='}'){
                    if(c=='{'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                else{
                    if(c=='['){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(!st.empty())return false;
        return true;
    }
};