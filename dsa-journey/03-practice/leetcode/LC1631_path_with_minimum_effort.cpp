class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=(int)heights.size(),n=(int)heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        dist[0][0]=0;
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [d,x,y]=pq.top();
            pq.pop();
            if(d>dist[x][y]) continue;
            if(x==m-1&&y==n-1) return d;
            for(int i=0;i<4;i++){
                int nr=x+dr[i],nc=y+dc[i];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                int diff=abs(heights[x][y]-heights[nr][nc]);
                int cnt=max(d,diff);
                if(cnt<dist[nr][nc]){
                    dist[nr][nc]=cnt;
                    pq.push({cnt,nr,nc});
                }
            }
        }
        return 0;
    }
};
