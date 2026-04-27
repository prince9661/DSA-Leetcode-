class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(temperatures[st.top()]>temperatures[i]){
                st.push(i);
                continue;
            }
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int j=st.top();
                st.pop();
                ans[j]=i-j;
            }
            st.push(i);
        }
        return ans;
    }
};