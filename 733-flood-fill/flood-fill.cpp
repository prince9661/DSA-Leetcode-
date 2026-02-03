class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        if (initial == color) return image; 
        stack<pair<int,int>>st;
        st.push({sr,sc});
        image[sr][sc]=color;
        while(!st.empty()){
            auto [x,y]=st.top();
            st.pop();
            
            if(x>0 && image[x-1][y]==initial){
                image[x-1][y]=color;
                st.push({x-1,y});
            }
            if(y>0 && image[x][y-1]==initial){
                image[x][y-1]=color;
                st.push({x,y-1});
            }
            if(x<image.size()-1 && image[x+1][y]==initial){
                image[x+1][y]=color;
                st.push({x+1,y});
            }
            if(y<image[x].size()-1 && image[x][y+1]==initial){
                image[x][y+1]=color;
                st.push({x,y+1});
            }
        }
        return image;
    }
};