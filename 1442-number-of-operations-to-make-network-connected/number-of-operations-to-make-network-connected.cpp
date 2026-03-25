class Solution {
public:
    int find(int x,vector<int>&parent){
        if(parent[x]==x)return x;
        int temp=find(parent[x],parent);
        parent[x]=temp;
        return temp;
    }
    bool unionfind(int x,int y,vector<int>&parent,vector<int>&rank){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py)return false;
        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        if(rank[py]>rank[px]){
            parent[px]=py;
        }
        else{
            parent[px]=py;
            rank[px]++;
        }
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()){
            return -1;
        }
        int ans=n-1-connections.size();
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        // int ans=0;

        for(int i=0;i<connections.size();i++){
            bool connect = unionfind(connections[i][0],connections[i][1],parent,rank);
            if(connect==false){
                ans++;
            }
        }
        return ans;
    }
};