class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=(int)rooms.size();
        vector<bool> keys(n,false);
        queue<int> q;
        keys[0]=true;
        q.push(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int& k:rooms[x]){
                if(!keys[k]){
                    keys[k]=true;
                    q.push(k);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!keys[i]) return false;
        }
        return true;
    }
};
