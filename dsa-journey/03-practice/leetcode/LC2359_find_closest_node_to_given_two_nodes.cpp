class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=(int)edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        int u=node1,d=0;
        while(u!=-1&&dist1[u]==-1){
            dist1[u]=d;
            d++;
            u=edges[u];
        }
        u=node2,d=0;
        while(u!=-1&&dist2[u]==-1){
            dist2[u]=d;
            d++;
            u=edges[u];
        }
        int best=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]==-1||dist2[i]==-1) continue;
            int m=max(dist1[i],dist2[i]);
            if(m<best){
                best=m;
                ans=i;
            }
        }
        return ans;
    }
};
