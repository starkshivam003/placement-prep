class Solution {
public:
    int find(int x,vector<int>& parent){
        if(parent[x]!=x) parent[x]=find(parent[x],parent);
        return parent[x];
    }
    bool unite(int a,int b,vector<int>& parent,vector<int>& sz){
        a=find(a,parent);
        b=find(b,parent);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=(int)points.size();
        vector<array<int,3>> edges;
        edges.reserve(n * (n - 1) / 2);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        vector<int> parent(n);
        vector<int> sz(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        int total=0,taken=0;
        for(auto& [cost,u,v]:edges){
            if(unite(u,v,parent,sz)){
                total+=cost;
                if(++taken==n-1) break;
            }
        }
        return total;
    }
};
