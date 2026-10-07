/*class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=(int)edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(vector<int>& e:edges){
            adj[e[0]].push_back(e[1]);   
            adj[e[1]].push_back(e[0]);   
        }
        for(int i=0;i<n+1;i++){
            if((int)adj[i].size()>1){
                return i;
            }
        }
        return 0;
    }
};*/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0],b=edges[0][1];
        return (a==edges[1][0]||a==edges[1][1])?a:b;
    }
};
