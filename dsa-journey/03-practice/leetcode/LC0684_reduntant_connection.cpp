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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=(int)edges.size();
        vector<int> parent(n+1);
        vector<int> sz(n+1,1);
        for(int i=1;i<n+1;i++) parent[i]=i;
        for(auto& e:edges){
            if(!unite(e[0],e[1],parent,sz)) return e;
        }
        return {};
    }
};
