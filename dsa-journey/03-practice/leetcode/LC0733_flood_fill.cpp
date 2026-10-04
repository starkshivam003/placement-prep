class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=(int)image.size(),n=(int)image[0].size();
        int orig=image[sr][sc];
        if(orig==color) return image;
        image[sr][sc]=color;
        int dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=x+dr[i],nc=y+dc[i];
                if(nr<0||nc<0||nr>=m||nc>=n) continue;
                if(image[nr][nc]!=orig) continue;
                image[nr][nc]=color;
                q.push({nr,nc});
            }
        }
        return image;
    }
};
