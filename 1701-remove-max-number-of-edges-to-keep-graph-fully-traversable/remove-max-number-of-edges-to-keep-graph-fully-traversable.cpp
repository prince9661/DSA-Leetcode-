class Solution {
public:
    int find(vector<int>&parent,int x){
        if(parent[x]==x)return x;
        int temp=find(parent,parent[x]);
        parent[x]=temp;
        return temp;
    }
    bool unionset(int x,int y,vector<int>&parent,vector<int>&rank){
        int px=find(parent,x);
        int py=find(parent,y);
        if(px==py)return false;
        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else{
            parent[px]=py;
            rank[py]++;
        }
        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        vector<int>parent1(n+1);
        vector<int>parent2(n+1);
        vector<int>rank1(n+1,1);
        vector<int>rank2(n+1,1);
        for(int i=0;i<=n;i++){
            parent1[i]=i;
            parent2[i]=i;
        }
        int ans=0;
        int count1=0;
        int count2=0;
        for(int i=0;i<edges.size();i++){
            int cat=edges[i][0];
            int x=edges[i][1];
            int y=edges[i][2];
            
            if(cat==3){
                bool first=unionset(x,y,parent1,rank1);
                bool second=unionset(x,y,parent2,rank2);
                if(first==false && second==false){
                    ans++;
                }
                if(first==true){
                    count1++;
                }
                if(second==true){
                    count2++;
                }
                
            }
            if(cat==2){
                bool first=unionset(x,y,parent1,rank1);
                if(first==false){
                    ans++;
                }else{
                    count1++;
                }
            }
            if(cat==1){
                bool second=unionset(x,y,parent2,rank2);
                if(second==false){
                    ans++;
                }else{
                    count2++;
                }
            }
        }
        if(count1 !=n-1 || count2 != n-1)return -1;
        return ans;

    }
};