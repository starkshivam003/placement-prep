class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<vector<int>> conn(n,vector<int>(n,0));
        for(const vector<int>& r:roads){
            int a=r[0],b=r[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            conn[a][b]=1;
            conn[b][a]=1;
        }
        int mac=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int road=(int)adj[i].size()+(int)adj[j].size()-(conn[i][j]?1:0);
                mac=max(mac,road);
            }
        }
        return mac;
    }
};

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for (auto& r : roads) { deg[r[0]]++; deg[r[1]]++; }

        // highest degree and second-highest (strictly smaller) degree
        int max1 = 0, max2 = 0;
        for (int d : deg) max1 = max(max1, d);
        for (int d : deg) if (d < max1) max2 = max(max2, d);

        long long cnt1 = 0, cnt2 = 0;           // how many cities have max1 / max2
        for (int d : deg) {
            if (d == max1) cnt1++;
            else if (d == max2) cnt2++;
        }

        if (cnt1 >= 2) {
            // best pair = two max1 cities: 2*max1, minus 1 only if ALL such pairs are connected
            long long edgesInside = 0;           // roads with both ends of degree max1
            for (auto& r : roads)
                if (deg[r[0]] == max1 && deg[r[1]] == max1) edgesInside++;
            long long allPairs = cnt1 * (cnt1 - 1) / 2;
            return edgesInside < allPairs ? 2 * max1 : 2 * max1 - 1;
        }

        // exactly one city u with max1: pair it with a max2 city
        long long edgesToU = 0;                  // roads between u and a max2 city
        for (auto& r : roads) {
            int a = deg[r[0]], b = deg[r[1]];
            if ((a == max1 && b == max2) || (a == max2 && b == max1)) edgesToU++;
        }
        return edgesToU < cnt2 ? max1 + max2 : max1 + max2 - 1;
    }
};
