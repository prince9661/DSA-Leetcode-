class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pre(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(heights[st.top()]<heights[i]){
                st.push(i);
                continue;
            }
            while(!st.empty()&& heights[st.top()]>heights[i] ){
                int j=st.top();
                st.pop();
                pre[j]=i;

            }
            st.push(i);
        }
        vector<int>post(n,n);
        stack<int>stc;
        for(int i=0;i<n;i++){
            if(stc.empty()){
                stc.push(i);
                continue;
            }
            if(heights[stc.top()]<heights[i]){
                stc.push(i);
                continue;
            }
            while(!stc.empty()&& heights[stc.top()]>heights[i] ){
                int j=stc.top();
                stc.pop();
                post[j]=i;

            }
            stc.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int res=(post[i]-pre[i]-1)*heights[i];
            ans=max(ans,res);
        }
        return ans;
    }
};