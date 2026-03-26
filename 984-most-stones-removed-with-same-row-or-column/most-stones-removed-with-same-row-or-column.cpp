class Solution {
public:
    int find(int x,unordered_map<int,int>&mp){
        if(mp.find(x)==mp.end()){
            mp[x]=x;
            return x;
        }
        if(mp[x]!=x){
            mp[x]=find(mp[x],mp);
        }
        return mp[x];
        
    }
    void dsu(int x,int y,unordered_map<int,int>&parent){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py)return;
        parent[px]=py;
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int>parent;

        for(int i=0;i<stones.size();i++){
            dsu(stones[i][0],stones[i][1]+20000,parent);
        }
        int count=0;
        for(auto it:parent){
            if(it.first==it.second)count++;
        }
        
        return stones.size()-count;
    }
};